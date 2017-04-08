
#define _XTAL_FREQ 4000000
#include <xc.h>
#include "lcd.h"


void LCD_RS(char x){
    //PORTA bit 4
    if(x) LCD_buff = LCD_buff | 0x10;
    else  LCD_buff = LCD_buff & 0xef;
    
    return;
    
}

void LCD_RW(char x){
    //PORTA bit 6
    if(x) LCD_buff = LCD_buff | 0x40;
    else  LCD_buff = LCD_buff & 0xbf;
    
    return;
    
}

void LCD_EN(){
    //PORTA bit 7
    
    PORTA = LCD_buff;
    
    PORTAbits.RA7 = 1;
    
    __delay_ms(10);
    
    PORTAbits.RA7 = 0;
    
    return;
    
}

//Writes nibble to 4 LSBs of LCD_buff
void LCD_data(unsigned char nib){
    
    LCD_buff = LCD_buff & 0xf0;
    nib = nib & 0x0f;
    LCD_buff = LCD_buff | nib;
    
    return;
}

//Outputs a byte of data to the LCD, regsel = 1 for data, 0 for command
void LCD_out(char regsel, char data){
    
    LCD_RW(0);              //Write to lcd
    LCD_RS(regsel);         //Select between data or command
    
    LCD_data(data >> 4);
    LCD_EN();
    
    LCD_data(data);
    LCD_EN();
    
}

void LCD_write(char line, char text[16]){
    
    LCD_out(0, 0x80+16*line);
    
    for(char i=0; i<16; i++){
        LCD_out(1, text[i]);
        LCD_out(0, 0x14);
    }
    
    
}

void LCD_ini(){
    
    LCD_RW(0);              //Write to lcd
    LCD_RS(0);              //Command
    
    __delay_ms(15);
    
    LCD_data(0x03);
    LCD_EN();
    __delay_ms(5);
    
    LCD_data(0x03);
    LCD_EN();
    __delay_us(160);
    
    LCD_data(0x02);
    LCD_EN();
    __delay_us(160);
    
    LCD_out(0,0x28);
    LCD_out(0,0x06);
    LCD_out(0,0x0c);
    LCD_out(0,0x80);
    
    
    
    
}
