/*
 * File:   main.c
 * Author: Aymen
 *
 * Created on April 24, 2017, 8:45 AM
 */


#include <htc.h>

int participations[15] = {0};
int minParticipation = -1;
int compt = 0;
int countDown = 0;

interrupt void interruption (void);
void updateMinParticiations(void);
void setMinParticiations( int );
void selectParticipant(void);
void affichage( int );

void main(void) {
    
    TRISA = 0x00;
    TRISB = 0x01;
    TRISC = 0xFF;
    TRISD = 0xFF;
    
    PORTA = 0x00; // decimal
    PORTB = 0x04; // unitaire
    PORTC = 0x00;
    PORTD = 0x00;
    
    INTCON = 0x90;
    
    while ( 1 ) {
        
    }
}

interrupt void interruption (void) {
    
    if ( INTF ) {
        
        INTF = 0;
        RB1 = 1;
        RB2 = 0;
        INTE = 0;
        TMR0IE = 1;
        TMR0 = 131;
        OPTION_REG = 0xD2;// 0xD3; // xxxx 
        compt = 0;
        countDown = 3;
        affichage(countDown);
    }
    else {
        
        TMR0IF = 0;
        compt++;
        if ( compt == 125 ) {
            compt = 0;
            countDown--;
            affichage(countDown);
            if ( countDown == 0 ) {
                RB1 = 0;
                RB2 = 1;
                updateMinParticiations();
                selectParticipant();
                TMR0IE = 0;
                INTE = 1;
            }
        }
    }
}

void updateMinParticiations(void) {
    
    minParticipation = -1;
    
    if ( RC0 )
        setMinParticiations( participations[0] );
    if ( RC1 )
        setMinParticiations( participations[1] );
    if ( RC2 )
        setMinParticiations( participations[2] );
    if ( RC3 )
        setMinParticiations( participations[3] );
    if ( RC4 )
        setMinParticiations( participations[4] );
    /*
    if ( RC5 )
        setMinParticiations( participations[5] );
    if ( RC6 )
        setMinParticiations( participations[6] );
    if ( RC7 )
        setMinParticiations( participations[7] );
    if ( RD0 )
        setMinParticiations( participations[8] );
    if ( RD1 )
        setMinParticiations( participations[9] );
    if ( RD2 )
        setMinParticiations( participations[10] );
    if ( RD3 )
        setMinParticiations( participations[11] );
    if ( RD4 )
        setMinParticiations( participations[12] );
    if ( RD5 )
        setMinParticiations( participations[13] );
    if ( RD6 )
        setMinParticiations( participations[14] );
     */
}

void selectParticipant(void) {
    
    if ( minParticipation == -1 )
        affichage( 0 );
    else if ( RC0 && participations[0] == minParticipation ) {
        affichage( 1 );
        participations[0]++;
    }
    else if ( RC1 && participations[1] == minParticipation ) {
        affichage( 2 );
        participations[1]++;
    }
    else if ( RC2 && participations[2] == minParticipation ) {
        affichage( 3 );
        participations[2]++;
    }
    else if ( RC3 && participations[3] == minParticipation ) {
        affichage( 4 );
        participations[3]++;
    }
    else if ( RC4 && participations[4] == minParticipation ) {
        affichage( 5 );
        participations[4]++;
    }
    /*
    else if ( RC5 && participations[5] == minParticipation ) {
        affichage( 6 );
        participations[5]++;
    }
    else if ( RC6 && participations[6] == minParticipation ) {
        affichage( 7 );
        participations[6]++;
    }
    else if ( RC7 && participations[7] == minParticipation ) {
        affichage( 8 );
        participations[7]++;
    }
    else if ( RD0 && participations[8] == minParticipation ) {
        affichage( 9 );
        participations[8]++;
    }
    else if ( RD1 && participations[9] == minParticipation ) {
        affichage( 10 );
        participations[9]++;
    }
    else if ( RD2 && participations[10] == minParticipation ) {
        affichage( 11 );
        participations[10]++;
    }
    else if ( RD3 && participations[11] == minParticipation ) {
        affichage( 12 );
        participations[11]++;
    }
    else if ( RD4 && participations[12] == minParticipation ) {
        affichage( 13 );
        participations[12]++;
    }
    else if ( RD5 && participations[13] == minParticipation ) {
        affichage( 14 );
        participations[13]++;
    }
    else if ( RD6 && participations[14] == minParticipation ) {
        affichage( 15 );
        participations[14]++;
    }
    */
}

void setMinParticiations( int value ) {
    
    if ( minParticipation == -1 )
        minParticipation = value;
    else if ( value < minParticipation )
        minParticipation = value;
}

void affichage( int valeur ) {
    
    switch ( valeur ) {
        
        case 0:
            PORTA = 0x00;
            RB4 = 0;
            RB5 = 0;
            RB6 = 0;
            RB7 = 0;
            break;
        case 1:
            PORTA = 0x00;
            RB4 = 1;
            RB5 = 0;
            RB6 = 0;
            RB7 = 0;
            break;
        case 2:
            PORTA = 0x00;
            RB4 = 0;
            RB5 = 1;
            RB6 = 0;
            RB7 = 0;
            break;
        case 3:
            PORTA = 0x00;
            RB4 = 1;
            RB5 = 1;
            RB6 = 0;
            RB7 = 0;
            break;
        case 4:
            PORTA = 0x00;
            RB4 = 0;
            RB5 = 0;
            RB6 = 1;
            RB7 = 0;
            break;
        case 5:
            PORTA = 0x00;
            RB4 = 1;
            RB5 = 0;
            RB6 = 1;
            RB7 = 0;
            break;
        case 6:
            PORTA = 0x00;
            RB4 = 0;
            RB5 = 1;
            RB6 = 1;
            RB7 = 0;
            break;
        case 7:
            PORTA = 0x00;
            RB4 = 1;
            RB5 = 1;
            RB6 = 1;
            RB7 = 0;
            break;
        case 8:
            PORTA = 0x00;
            RB4 = 0;
            RB5 = 0;
            RB6 = 0;
            RB7 = 1;
            break;
        case 9:
            PORTA = 0x00;
            RB4 = 1;
            RB5 = 0;
            RB6 = 0;
            RB7 = 1;
            break;
        case 10:
            PORTA = 0x01;
            RB4 = 0;
            RB5 = 0;
            RB6 = 0;
            RB7 = 0;
            break;
        case 11:
            PORTA = 0x01;
            RB4 = 1;
            RB5 = 0;
            RB6 = 0;
            RB7 = 0;
            break;
        case 12:
            PORTA = 0x01;
            RB4 = 0;
            RB5 = 1;
            RB6 = 0;
            RB7 = 0;
            break;
        case 13:
            PORTA = 0x01;
            RB4 = 1;
            RB5 = 1;
            RB6 = 0;
            RB7 = 0;
            break;
        case 14:
            PORTA = 0x01;
            RB4 = 0;
            RB5 = 0;
            RB6 = 1;
            RB7 = 0;
            break;
        case 15:
            PORTA = 0x01;
            RB4 = 1;
            RB5 = 0;
            RB6 = 1;
            RB7 = 0;
            break;
    }
    
    for ( int i = 0; i < 5; i++ ) {
        participations[i]++;
    }
}
