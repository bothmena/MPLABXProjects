    #INCLUDE p16f84.inc
    
    #DEFINE LED PORTA,0
    #DEFINE BUTTON1 PORTB,4
    #DEFINE BUTTON2 PORTB,5
    #DEFINE BUTTON3 PORTB,6
    #DEFINE BUTTON4 PORTB,7
    
    
    
BANK0 MACRO
    BCF STATUS,RP0
    ENDM
    
BANK1 MACRO 
    BSF STATUS,RP0
    ENDM
    
    ORG 0x00
    GOTO START
    
    ORG 0x04
    GOTO INTERRUPTOR
    
START ORG 0x05
    BANK0
    MOVLW 0xF0
    MOVWF TRISA
    MOVLW 0xFF
    MOVWF TRISB
    MOVLW 0x88
    MOVWF INTCON
    BANK1
    CLRF PORTA
    GOTO LOOP
    
LOOP
    GOTO LOOP
    
INTERRUPTOR
    BCF INTCON,1
    BSF LED
    RETFIE
    ;BTFSC BUTTON1
    ;GOTO SETLED
    ;GOTO CLEARLED
    
SETLED
    BSF LED
    RETFIE
    
CLEARLED
    BCF LED
    RETFIE

    END