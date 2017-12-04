#include  "config.h"

    .section    .text
    .global     main

main:
        ; set clock to full speed
        ldi	    r24, 0x80
        sts	    CLKPR, r24
        sts	    CLKPR, r1

        ; configure portB pin 4 as output (Arduino pin 12)
        sbi	    _DDRB, BUZZ_PIN
        cbi	    _PORTB, BUZZ_PIN
L0e:    sbi	    _PORTB, BUZZ_PIN
      	ldi	    r24, 0x3F
        ldi	    r25, 0x1F
L14:    sbiw	r24, 0x01
       	brne	L14
       	cbi	    _PORTB, BUZZ_PIN
        ldi	    r24, SREG
     	ldi	    r25, 0x1F
L22:   	sbiw	r24, 0x01
       	brne	L22
        rjmp	L0e
