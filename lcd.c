
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

void LCD_EN(char x){
    //PORTA bit 7
    if(x) PORTA = LCD_buff;
    PORTAbits.RA7 = x;
    
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
void LCD_out(char regsel, unsigned char data){
    
    LCD_RW(0);              //Write to lcd
    LCD_RS(regsel);         //Select between data or command
    
    LCD_data(data >> 4);
    LCD_EN(1);
    LCD_EN(0);
    
    LCD_data(data);
    LCD_EN(1);
    LCD_EN(0);
}

void LCD_ini(){
    
    

    
}