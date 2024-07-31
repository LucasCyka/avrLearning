#define F_CPU 8000000UL

#include <util/delay.h>

int main(){

    volatile unsigned char *DDRB = (volatile unsigned char *) 0x37;
    volatile unsigned char *PORTB = (volatile unsigned char *) 0x38;


    *DDRB = 255;

    while (1)
    {
        *PORTB = 255;
        _delay_ms(200);
        *PORTB = 0;
        _delay_ms(200);
    }
    

    return 0;
}