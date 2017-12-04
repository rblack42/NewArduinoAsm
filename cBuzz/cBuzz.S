#include  "config.h"

    .section    .text
    .global     main

main:
        ldi	    r24, 0x80
        sts	    0x0061, r24
        sts	    0x0061, r1
        sbi	    0x04, 4
        cbi	    0x05, 4
L0e:    sbi	    0x05, 4
      	ldi	    r24, 0x3F
        ldi	    r25, 0x1F
L14:    sbiw	r24, 0x01
       	brne	L14
       	rjmp	L1a 
L1a:    nop
       	cbi	    0x05, 4
        ldi	    r24, 0x3F
     	ldi	    r25, 0x1F
L22:   	sbiw	r24, 0x01
       	brne	L22
        rjmp	L28
L28:    nop
        rjmp	L0e
