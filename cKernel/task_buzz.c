#include <avr/io.h>
#include "task_buzz.h"

#define BUZZ_PIN         4
#define BUZZ_OFF         (PORTB &= ~(1<<BUZZ_PIN))
#define BUZZ_CONFIG      (DDRB |= (1<<BUZZ_PIN))

int bcount = 0;

void task_buzz_init(void) {
    BUZZ_CONFIG;
    BUZZ_OFF;
}

void task_buzz(void) {
    bcount++;
    if(bcount == 1) {
        PORTB ^= _BV(BUZZ_PIN);
        bcount = 0;
    }
}

