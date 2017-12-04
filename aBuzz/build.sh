#!/usr/bin/env bash
proj = aBuzz
cflags = "-mmcu=atmega328p -nostartfiles"
avr-gcc ${cflags} -c ${proj}.S -o ${proj}.o
avr-gcc ${cflags} -c timer.S -o timer.o
avr-gcc ${cflags}  $PROJ.o timer.o -o $1.elf -lm
avr-objcopy -O ihex -R .eeprom ${proj}.elf ${proj}.hex
