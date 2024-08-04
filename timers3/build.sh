#!/usr/bin/bash

avr-gcc -mmcu=attiny2313 -o main.o main.c

avr-objcopy -O ihex -j.text -j.data main.o main.hex
