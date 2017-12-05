#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN         5                                                   
#define LED_ON          (PORTB |= (1<<LED_PIN))                             
#define LED_OFF         (PORTB &= ~(1<<LED_PIN))                            
#define LED_CONFIG      (DDRB |= (1<<LED_PIN))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

volatile uint8_t intrs;

ISR(TIMER0_OVF_vect) {
	/* this ISR is called when TIMER0 overflows */
	intrs++;
	/* strobe PORTB.5 - the LED on Arduino UNO boards */
	if (intrs >= 61){
		PORTB ^= _BV(5);
		intrs = 0;
	}
}

void timer0_init(void) {
    TCCR0B |= _BV(CS02) | _BV(CS00);                                        
    TCNT0 = 0;                                                              
    TIMSK0 |= _BV(TOIE0);         
}

int main(void) {
    CPU_PRESCALE(0);
    LED_CONFIG;
    LED_OFF;
    timer0_init();
	intrs = 0;
	sei();
	while (1);
}

