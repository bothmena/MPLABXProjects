/*
 * File:   main.c
 * Author: Aymen
 *
 * Created on April 28, 2017, 8:45 AM
 */


#include <htc.h>

int compt = 0;
int initVal = 0;
int countDown = 0;

void affichage( int, int );
interrupt void interruption (void);

void main(void) {
    
    // confog I/O
    TRISB = 0x03;
    TRISC = 0x00;
    
    // config interruptions
    INTCON = 0x90;
    
    // init
    PORTB = 0x00; // unitaire
    PORTC = 0x00;
    RB2 = 0;
    RB3 = 1;
    
    while ( 1 ) {
        
    }
}

interrupt void interruption (void) {
    
    if ( INTF ) {
        
        INTF = 0;
        if ( TMR0IE == 0 ) {
            //start
            TMR0IE = 1;
            TMR0 = 131;
            OPTION_REG = 0xD2;// 0xD3; // xxxx  
            compt = 0;
            if ( RB1 ) //examen
                initVal = 90;
            else // DS
                initVal = 60;
            countDown = initVal;
            affichage(countDown/10, countDown%10);
            RB2 = 0;
            RB3 = 0;
        }
        else {
            //reset
            TMR0IE = 0;
            affichage(0, 0);
            RB2 = 0;
            RB3 = 1;
        }
    }
    else {
        
        TMR0IF = 0;
        compt++;
        if ( compt == 125 ) {
            compt = 0;
            countDown--;
            affichage(countDown/10, countDown%10);
            if ( countDown == initVal/2 ) {
                
                RB2 = 1;
            }
            else if ( countDown == 0 ) {
                TMR0IE = 0;
                RB2 = 0;
                RB3 = 1;
            }
        }
    }
}

void affichage(int dec, int unit ) {
    
    switch ( unit ) {
        
        case 0:
            PORTC = 0x00;
            break;
        case 1:
            PORTC = 0x01;
            break;
        case 2:
            PORTC = 0x02;
            break;
        case 3:
            PORTC = 0x03;
            break;
        case 4:
            PORTC = 0x04;
            break;
        case 5:
            PORTC = 0x05;
            break;
        case 6:
            PORTC = 0x06;
            break;
        case 7:
            PORTC = 0x07;
            break;
        case 8:
            PORTC = 0x08;
            break;
        case 9:
            PORTC = 0x09;
            break;
    }
    
    switch ( dec ) {
        
        case 0:
            RC4 = 0;
            RC5 = 0;
            RC6 = 0;
            RC7 = 0;
            break;
        case 1:
            RC4 = 1;
            RC5 = 0;
            RC6 = 0;
            RC7 = 0;
            break;
        case 2:
            RC4 = 0;
            RC5 = 1;
            RC6 = 0;
            RC7 = 0;
            break;
        case 3:
            RC4 = 1;
            RC5 = 1;
            RC6 = 0;
            RC7 = 0;
            break;
        case 4:
            RC4 = 0;
            RC5 = 0;
            RC6 = 1;
            RC7 = 0;
            break;
        case 5:
            RC4 = 1;
            RC5 = 0;
            RC6 = 1;
            RC7 = 0;
            break;
        case 6:
            RC4 = 0;
            RC5 = 1;
            RC6 = 1;
            RC7 = 0;
            break;
        case 7:
            RC4 = 1;
            RC5 = 1;
            RC6 = 1;
            RC7 = 0;
            break;
        case 8:
            RC4 = 0;
            RC5 = 0;
            RC6 = 0;
            RC7 = 1;
            break;
        case 9:
            RC4 = 1;
            RC5 = 0;
            RC6 = 0;
            RC7 = 1;
            break;
    }
}
