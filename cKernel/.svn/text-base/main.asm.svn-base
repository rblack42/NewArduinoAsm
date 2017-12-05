	.file	"main.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__  = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	__vector_23
	.type	__vector_23, @function
__vector_23:
	push __zero_reg__
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
	push r29
	push r28
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: Signal */
/* frame size = 0 */
	lds r24,intrs
	subi r24,lo8(-(1))
	sts intrs,r24
	lds r24,intrs
	cpi r24,lo8(61)
	brlo .L3
	ldi r26,lo8(37)
	ldi r27,hi8(37)
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ld r25,Z
	ldi r24,lo8(32)
	eor r24,r25
	st X,r24
	sts intrs,__zero_reg__
.L3:
/* epilogue start */
	pop r28
	pop r29
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop __zero_reg__
	reti
	.size	__vector_23, .-__vector_23
.global	main
	.type	main, @function
main:
	push r29
	push r28
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 0 */
	ldi r26,lo8(69)
	ldi r27,hi8(69)
	ldi r30,lo8(69)
	ldi r31,hi8(69)
	ld r24,Z
	ori r24,lo8(5)
	st X,r24
	ldi r26,lo8(110)
	ldi r27,hi8(110)
	ldi r30,lo8(110)
	ldi r31,hi8(110)
	ld r24,Z
	ori r24,lo8(1)
	st X,r24
	ldi r30,lo8(36)
	ldi r31,hi8(36)
	ldi r24,lo8(-1)
	st Z,r24
	ldi r30,lo8(70)
	ldi r31,hi8(70)
	st Z,__zero_reg__
	sts intrs,__zero_reg__
/* #APP */
 ;  41 "main.c" 1
	sei
 ;  0 "" 2
/* #NOAPP */
.L5:
	rjmp .L5
	.size	main, .-main
	.comm intrs,1,1
.global __do_clear_bss
