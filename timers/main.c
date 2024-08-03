//timer res = 1 /input frequency = period of frequency.

//say my clock speed is of 1mhz
//that means that my period is of 1/1E6 seconds or 1 microsecond
//if say I want that my wait value is of 1/20 seconds (0.05s) and my clock register counts every clock tick
//that means that my counter will count till 0.05s/1microsecond before it reaches my desired wait time:
//50.000. Since the clock tick will start counting from zero, I need to subtact 1.
//so 49.999 counts to 0.05 seconds.

// to start a timer, say for example the time register/counter 1, I need to supply it with a clock
// I do this by changing the first 3 bits in the counter register(TCCR1B). 
// If I set CS10 to 1, it will supply the timer with the same clock as the cpu, without dividing its
//value (no prescaling or prescaling of *1).

//remeber the counter counts independtly of the our avr (syncronous operation).

//TCNT1 register gives us the current value of the counters. It's stored in two registers of 8 bits
//but our handy c libraries hides this fact from us.

#include <avr/io.h>

#define F_CPU 1000000UL

int main(){

    DDRB  |= (1 << 0);
    PORTB |= (1 << 0);

    TCCR1B |= (1 << CS10); //timer 1 now is clocked to use 1MHZ without prescaling


    while(1){//main loop

        //I want toggle portb pin0 output at 25hz
        //that means toggle it every 1/50 (0.02) seconds. (in one period it will turn on and off)
        //TCNT1 will be inclemented every clock period. The clock frequency is 1/1000000
        //That means I need to toggle the LED when TCNT1 is equal to 0.02/1us -1 (it counts from zero)
        if (TCNT1 >= 19999){
            PORTB ^= (1 << 0);

            TCNT1 = 0; //reset counter
        }

    }


    return 0;
}