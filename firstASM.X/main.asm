
    #include p16f84.inc
    
    ORG 0x000
    
    GOTO DEBUT
    
DEBUT ORG 0x05
 
    BSF STATUS,RP0
    BCF TRISB,0
    BCF STATUS,RP0
    
BOUCLE
    BSF PORTB,0
    GOTO BOUCLE
    END
 