MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -O1

all: blink.hex

blink.elf: blink.c
	$(CC) $(CFLAGS) -o blink.elf blink.c

blink.hex: blink.elf
	avr-objcopy -O ihex blink.elf blink.hex

flash: blink.hex
	avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:blink.hex

clean:
	rm -f blink.elf blink.hex
