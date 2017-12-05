#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"

ISR(TIMER0_OVF_vect) {
    toggle = 1;
}


void timer0_init(void) {
    TCCR0B |= _BV(CS01) | _BV(CS00);  // divide by 64
    TCNT0 = 0;                                                              
    TIMSK0 |= _BV(TOIE0);
    toggle = 0;
    sei();
}
