#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 1000000UL

void init_timer(){

    TCCR1B |= (1 << WGM12); //start timer in CTC mode

    TIMSK |= (1 << OCIE1A); //active interrupt mask for channel A

    sei(); //activate global interrupts

    OCR1A = 15624; //1 second @1Mhz with 64 prescaler

    TCCR1B |= ((1 << CS10) | (1 << CS11));//start clock with 64 prescaler (using system's clock)

}

ISR(TIMER1_COMPA_vect){ //Timer/Counter1 Compare Match A. called when timer counter reaches OCR1A
    PORTB = ~(PORTB);
}

int main(){

    DDRB = 255;

    init_timer();

    while(1){
        
    }

    return 0;
}