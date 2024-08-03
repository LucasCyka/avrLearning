//again, to learn more about avr timers, I'm going to turn on or off a LED every second.
//To this I will make of of timer1 of attiny and make its counter inclement every 1000ms (1khz target frequency)

//after this I need to learn about interrupts, since this code can cause busy-waiting

#include <avr/io.h>

#define F_CPU 4000000UL

long millis = 0;

int main(){

    DDRB  |= (1 << 0);
    PORTB |= (1 << 0); 

    TCCR1B |= (1 << CS10); //clock will be running at 4mhz

    //prescale = 1
    // (1/1000s) / (1/4mhz) * prescale
    // (1/1000s) = time I need to wait
    // (1/4mhz) = time to inclement the counter by one

    while(1){

        if(TCNT1 >= 3999){ //one milisecond has passed

            TCNT1 = 0;
            millis += 1; 

        }

        if (millis == 1000){ //one second has passed
            millis = 0;
            PORTB ^= (1 << 0);  
        }

    }

}