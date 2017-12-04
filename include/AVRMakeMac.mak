OBJS	= $(CSRCS:.c=.o) $(ASRCS:.S=.o)


ARDUINO = /Applications/Arduino.app/Contents/Java/hardware

TOOLS   = $(ARDUINO)/tools/avr/bin
GCC		= $(TOOLS)/avr-gcc 
OBJCOPY	= $(TOOLS)/avr-objcopy 
OBJDUMP = $(TOOLS)/avr-objdump
RM      = rm -f 
DUDE    = $(TOOLS)/avrdude


INCLUDES	+= -I"$(ARDUINO)/arduino/avr/cores/arduino"
DUDECNF     = -C"$(ARDUINO)/tools/avr/etc/avrdude.conf"

all:	$(TARGET).hex
