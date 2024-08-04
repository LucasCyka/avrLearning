//using timers in ctc mode
//ctc = clear timer on compare

#include <avr/io.h>

#define F_CPU 1000000UL

int main(){

    TCCR1B |= (1 << WGM12); //start time in CTC mode

    //1second = 1/(1/(1E6/64))-1
    OCR1A = 15624; //max value of the counter to trigger OCF1A

    TCCR1B |= ((1 << CS11) | (1 << CS10)); //set timer to use clock with 64 prescale

    DDRB = 255;

    while (1)
    {
        //TIFR is the register used to detect interrupt events like compare matches (this case) and overflow
        if(TIFR & (1 << OCF1A)){
            TIFR |= (1 << OCF1A); //OCF1A can be cleared by writing a logic 1 to its bit location

            PORTB = ~(PORTB);

        }
    }
    


    return 0;
}