MCU=atmega32a
DF_CPU=16000000UL

CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Os -DF_CPU=$(DF_CPU) -mmcu=$(MCU) 

TARGET=main

HEX_DIR=~/storage/ms-win/avr

HEADERS=common/types.h common/macros.h 
HEADERS+=MCAL/DIO.h MCAL/Timer0.h
HEADERS+=HAL/Keypad.h HAL/BCD7Seg.h

SOURCES=MCAL/DIO.c MCAL/Timer0.c
SOURCES+=HAL/Keypad.c HAL/BCD7Seg.c

all: $(TARGET).hex

$(TARGET).hex: $(SOURCES) $(TARGET).c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $(TARGET).o $(TARGET).c
	$(CC) $(CFLAGS) -mmcu=$(MCU) $(TARGET).o $(SOURCES) -o $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex
	cp $(TARGET).hex $(HEX_DIR)/$(TARGET).hex

flash:
	doas avrdude -P /dev/ttyUSB0 -c arduino -p atmega32a -U flash:w:$(TARGET).hex:i


clean:
	/bin/rm -f *.o *.elf *.hex
