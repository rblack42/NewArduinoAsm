; configuration for blink
#include <avr/io.h>
#include "../include/AVRSpecialRegs.inc"

#define LED_PIN     5       // UNO board LED
#define LED_DIR     _DDRB
#define LED_PORT    _PORTB
