#include <avr/io.h>
#include "timer0.h"
#include "task_led.h"
#include "task_buzz.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

volatile uint8_t toggle;

int main(void) {
    CPU_PRESCALE(0);
    task_led_init();
    task_buzz_init();
    timer0_init();
	while (1) {
        if(toggle == 1) {
            task_led();
            task_buzz();
            toggle = 0;
        }
    }
}

