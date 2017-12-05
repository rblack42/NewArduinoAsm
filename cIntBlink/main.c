#include <avr/io.h>
#include "timer0.h"

#define LED_PIN         5                                                   
#define LED_ON          (PORTB |= (1<<LED_PIN))                             
#define LED_OFF         (PORTB &= ~(1<<LED_PIN))                            
#define LED_CONFIG      (DDRB |= (1<<LED_PIN))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

volatile uint8_t intrs;

int main(void) {
    CPU_PRESCALE(0);
    LED_CONFIG;
    LED_OFF;
    timer0_init();
	while (1);
}

