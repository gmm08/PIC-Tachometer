/* 
 * File:   lcd.h
 * Author: Guillem
 *
 * Created on 8 de abril de 2017, 9:41
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

//VARIABLES
char LCD_buff;

//FUNCIONS
void LCD_RS(char);
void LCD_RW(char);
void LCD_EN();
void LCD_data(unsigned char);
void LCD_ini();
void LCD_write(char, char[]);
void LCD_out(char, char);

    

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

