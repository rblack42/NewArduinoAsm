OBJS	= $(CSRCS:.c=.o) $(ASRCS:.S=.o)

#ARDUINO = "C:/Arduino/hardware"
ARDUINO = "C:\Program Files (x86)"/Arduino/hardware
TOOLS 	= $(ARDUINO)/tools/avr/bin


GCC	= $(TOOLS)/avr-gcc.exe
OBJCOPY	= $(TOOLS)/avr-objcopy.exe
OBJDUMP	= $(TOOLS)/avr-objdump.exe
RM		= del
DUDE	= $(TOOLS)/avrdude.exe

DUDECNF		= -C$(ARDUINO)/tools/avr/etc/avrdude.conf
INCLUDES	+= -I$(ARDUINO)/arduino/avr/variants/$(BINC)
INCLUDES	= -I$(ARDUINO)/arduino/avr/cores/arduino
INCLUDES	+=	-I$(ARDUINO)/tools/avr/avr/include/avr

all:	$(TARGET).hex $(TARGET).asm
