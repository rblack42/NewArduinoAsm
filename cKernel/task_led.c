#include <avr/io.h>
#include "task_led.h"

#define LED_PIN         5                                                   
#define LED_OFF         (PORTB &= ~(1<<LED_PIN))                            
#define LED_CONFIG      (DDRB |= (1<<LED_PIN))

int lcount = 0;

void task_led_init(void) {
    LED_CONFIG;
    LED_OFF;
}

void task_led(void) {
    lcount++;
    if(lcount == 500) {
        PORTB ^= _BV(LED_PIN);
        lcount = 0;
    }
}

