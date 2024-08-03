#!/usr/bin/bash

echo "Compilling now..."

avr-gcc -mmcu=attiny2313 -o main.o main.c

echo "Checking size..."

avr-size -C -x --mcu=attiny2313 main.o

echo "Creating ihex"

avr-objcopy -O ihex -j.text -j.data main.o main.hex
