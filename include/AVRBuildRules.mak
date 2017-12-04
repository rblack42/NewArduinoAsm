# standard build rules for all platforms

%.hex:  %.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.elf:  $(OBJS)
	$(GCC) -w -Os $(CFLAGS) -o $@ $^ -lm

%.o:    %.c
	$(GCC) -c $(CFLAGS) $< -o $@

%.o:    %.S
	$(GCC) -c $(AFLAGS) $< -o $@

%.lst:	%.elf
	$(OBJDUMP) $< --disassemble > $@

load:   $(TARGET).hex
	$(DUDE) $(DUDECNF) $(LFLAGS) -Uflash:w:$(TARGET).hex:i

%.lst:   %.elf
	$(OBJDUMP) -d $< > $@

clean:
	$(RM) $(TARGET).hex $(TARGET).elf *.o *.lst

%.sym:	%.S
	$(GCC) $(AFLAGS) -E -dM $< > $@
