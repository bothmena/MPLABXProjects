/*
 * File:   main.c
 * Author: Aymen
 *
 * Created on February 19, 2017, 7:27 PM
 */


#include <xc.h>

void show( int i );
void attente();

void main(void) {
    
    TRISA = 0xFF;
    TRISB = 0x00;
    
    PORTA = 0x00;
    PORTB = 0x00;
    
    int i = 0;
    
    while ( 1 ) {
        
        while ( RA0 ) {
            
            i = i++%6;
            show( i );
        }
    }
}

void show( int i ) {
    
    switch ( i ) {
        case 0:
            PORTB = 0x00;
            break;
        case 1:
            PORTB = 0x06;
            break;
        case 2:
            PORTB = 0x5B;
            break;
        case 3:
            PORTB = 0x4F;
            break;
        case 4:
            PORTB = 0x66;
            break;
        case 5:
            PORTB = 0x6D;
            break;
        case 6:
            PORTB = 0x7D;
            break;
    }
    attente();
}

void attente() {
    
    for ( int i = 0; i < 32; i++ ) {
        for ( int j = 0; j < 32; j++ );
    }
}
