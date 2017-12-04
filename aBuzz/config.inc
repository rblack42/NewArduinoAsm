; configuration for blink
#include <avr/io.h>
#include "../include/AVRSpecialRegs.inc"

#define BUZZ_PIN     4
#define BUZZ_DIR     _DDRB
#define BUZZ_PORT    _PORTB
