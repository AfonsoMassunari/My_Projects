#include "adc.h"
#include "pic18f4550.h"
#include "io.h"
#include "bits.h"

void adcInit(void) {
    //AN0-A0, AN1-A1 e AN2-A2 s�o anal�gicos e entradas
    pinMode(PIN_A0, INPUT);
    pinMode(PIN_A1, INPUT);
    pinMode(PIN_A2, INPUT);

    bitSet(ADCON0, 0); //liga ADC
    //config an0-2 como anal�gico
    ADCON1 = 0b00001100; //AN0,AN1 e AN2 s�o analogicos, a referencia � baseada na fonte
    ADCON2 = 0b11101010; //FOSC /32, 12 TAD, Alinhamento � direita e tempo de conv = 12 TAD
    
}

int adcRead(unsigned int channel) {
    unsigned int ADvalor;
   
    ADCON0 &= 0b11000011; //zera os bits do canal
    if(channel == 0){
        ADCON0 |= 0b00000000;
    }else if (channel == 1) {
        ADCON0 |= 0b00000100;
        //ADCON0 |= channel << 2;
    }else if( channel == 2){
        ADCON0 |= 0b00001000;
    }
    
    ADCON0 |= 0b00000010; //inicia conversao

    while (bitTst(ADCON0, 1)); // espera terminar a convers�o;

    ADvalor = ADRESH; // le o resultado
    ADvalor <<= 8;
    ADvalor += ADRESL;
    return ADvalor;
}