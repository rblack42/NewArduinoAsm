#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"

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
    intrs = 0;
    sei();
}
