#include "bits.h"
#include "io.h"
#include <pic18f4520.h>


//fun��o para controlar apenas o bit referente a um pino
void digitalWrite(int pin, int value){ 
    if(pin <8){
        if (value){  bitSet(PORTA,pin);}
        else{        bitClr(PORTA,pin);}
    }else if(pin<16){
        pin -=8;
        if (value){  bitSet(PORTB,pin);}
        else{        bitClr(PORTB,pin);}
    }else if(pin<24){
        pin -=16;
        if (value){  bitSet(PORTC,pin);}
        else{        bitClr(PORTC,pin);}
    }else if(pin<32){
        pin -=24;
        if (value){  bitSet(PORTD,pin);}
        else{        bitClr(PORTD,pin);}
    }else if(pin<40){
        pin -=32;
        if (value){  bitSet(PORTE,pin);}
        else{        bitClr(PORTE,pin);}
    }
 
}

//fun��o para ler apenas o bit referente a um pino
int digitalRead(int pin){
    if(pin <8){
        return bitTst(PORTA,pin);
    }else if(pin<16){
        return bitTst(PORTB,pin-8);
    }else if(pin<24){
        return bitTst(PORTC,pin-16);
    }else if(pin<32){
        return bitTst(PORTD,pin-24);
    }else if(pin<40){
        return bitTst(PORTE,pin-32);
    }
    return -1;
}

//fun��o para configurar apenas um pino como entrada ou sa�da
void pinMode(int pin, int type) {
    //porta
    if(pin <8){
        if (type){  bitSet(TRISA,pin);}
        else{       bitClr(TRISA,pin);}
    }else if(pin<16){
        if (type){  bitSet(TRISB,pin-8);}
        else{       bitClr(TRISB,pin-8);}
    }else if(pin<24){
        if (type){  bitSet(TRISC,pin-16);}
        else{       bitClr(TRISC,pin-16);}
    }else if(pin<32){
        if (type){  bitSet(TRISD,pin-24);}
        else{       bitClr(TRISD,pin-24);}
    }else if(pin<40){
        if (type){  bitSet(TRISE,pin-32);}
        else{       bitClr(TRISE,pin-32);}
    }
            
}