/*
 * File:   main.c
 * Author: Aymen
 *
 * Created on January 23, 2017, 11:17 AM
 */


#include <xc.h>

void main(void) {
    
    TRISB = 0xFE;
    PORTB = PORTB & 0xFE;
    
    while(1) {
        
        if( RB1 == 1 ) {
            RB0 = 1;
        } else {
            RB0 = 0;
        }
    }
    
    return;
}
