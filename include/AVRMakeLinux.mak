OBJS	= $(CSRCS:.c=.o) $(ASRCS:.S=.o)

ARDUINO	= /usr/share/arduino
TOOLS	= $(ARDUINO)/hardware/tools/avr/bin
GCC	= $(TOOLS)/avr-gcc 
OBJCOPY	= $(TOOLS)/avr-objcopy 
OBJDUMP = $(TOOLS)/avr-objdump
RM      = rm -f 
DUDE    = $(TOOLS)/avrdude

BASEDIR		= $(ARDUINO)/hardware
INCLUDES	= -I"$(BASEDIR)/arduino/avr/variants/$(BINC)"
INCLUDES	+= -I"$(BASEDIR)/tools/avr/avr/include/avr"
DUDECNF     	= -C"$(BASEDIR)/tools/avr/avrdude.conf"

all:	$(TARGET).hex
