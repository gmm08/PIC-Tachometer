
// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



#include <xc.h>
#include "lcd.h"




void interrupt isr(void){
    
    //CAPTURE MODULE INTERRUPT
    if(PIE1bits.CCP1IE && PIR1bits.CCP1IF){
        
        PIR1bits.CCP1IF = 0;
    }
    
    
    //TIMER1 OVERFLOW INTERRUPT
    if(PIE1bits.TMR1IE && PIR1bits.TMR1IF){
        
        PIR1bits.TMR1IF = 0;
    }
    
    return;
}


void main(void) {
    
    TRISA = 0x00;
    
    TRISB = 0x04;
    
    T1CON = 0x30;
    
    CCP1CON = 0x05;
    CMCON = 0x07;
    
    LCD_ini();
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIR1bits.CCP1IF = 0;
    PIE1bits.CCP1IE = 1;
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    
    LCD_write(1,"caca            ");
    
    while(1){
        
        
    }
    
    return;
}

