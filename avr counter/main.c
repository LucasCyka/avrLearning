//#define DDRB *((volatile unsigned char*)0x37) <I cant understand this shit, but it saves time

#define A 0b10000000
#define B 0b01000000
#define C 0b00100000
#define D 0b00010000
#define E 0b00001000
#define F 0b00000100
#define G 0b00000010

unsigned char numbers[10][7] = {
  {A,B,C,D,E,F,0}, //0
  {0,B,C,0,0,0,0}, //1
  {A,B,0,D,E,0,G}, //2
  {A,B,C,D,0,0,G}, //3
  {0,B,C,0,0,F,G}, //4
  {A,0,C,D,0,F,G}, //5
  {A,0,C,D,E,F,G}, //6
  {A,B,C,0,0,0,0}, //7
  {A,B,C,D,E,F,G}, //8
  {A,B,C,0,0,F,G} //9
  
};

int currentNumber = 0;

int main(){

    volatile unsigned char *DDRB =  (volatile unsigned char * )0x37;
    volatile unsigned char *PORTB = (volatile unsigned char * )0x38;

    *DDRB = 255;

    while (1){
        
        *PORTB = 0;

        for (long i =0; i < 1000;i++){
            *PORTB = 0;
        }

        for (int i = 0; i <= 6; i++){
            *PORTB |= numbers[currentNumber][i];
         }

        for (long i =0; i < 100000;i++){
            *DDRB = 255;
        }

        if(currentNumber >= 9){
            currentNumber = 0;
        }else{currentNumber++;}

    }

    return 0;
}