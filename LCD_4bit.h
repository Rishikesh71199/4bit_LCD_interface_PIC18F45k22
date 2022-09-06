/* 
 * File:   LCD_4bit.h
 * Author: Rishekesh
 *
 * Created on June 14, 2022, 4:13 PM
 * 
 * This 4bit LCD Driver is made for PIC18F45K22 MCU Provided by
 * Microchip
 */

#ifndef LCD_4BIT_H
#define	LCD_4BIT_H

// To mack changes in PORT no change this line
#define LCD  PORTC        // LCD commnected PORT
/**********************************************/
#define LCD_read  LCD       // LCC REading PORT
#define LCD_delay 10        // Delay LCD EN
#define RS      2           // RS Pin no
#define EN      3           // EN Pin no


// This Function is use for LCD command Transfer 
void LCD_command(unsigned char command)
{
    LCD = ((command & 0xF0)|(0<<RS)|(1<<EN)|(LCD_read & 0x03));     // RS = 0 , EN = 1 , 4bit_HSB Command
    __delay_ms(LCD_delay);
    LCD &= ~(1<<EN);        // EN = 0
    __delay_ms(LCD_delay);
    
    
     LCD = (((command << 4) & 0xF0)|(0<<RS)|(1<<EN)|(LCD_read & 0x03)); // RS = 0 , EN = 1 , 4bit_LSB Command 
    __delay_ms(LCD_delay);
    LCD &= ~(1<<EN);        // EN = 0
    __delay_ms(LCD_delay);   
}

// This Function is use for LCD Data Transfer 
void LCD_data (unsigned char data)
{
    LCD = ((data & 0xF0)|(1<<RS)|(1<<EN)|(LCD_read & 0x03));    // RS = 1 , EN = 1 , 4bit_HSB data
    __delay_ms(LCD_delay);
    LCD &= ~(1<<EN);        // EN = 0
    __delay_ms(LCD_delay);
    
    
    LCD = (((data << 4) & 0xF0)|(1<<RS)|(1<<EN)|(LCD_read & 0x03)); // RS = 1 , EN = 1 , 4bit_LSB data
    __delay_ms(LCD_delay);
    LCD &= ~(1<<EN);       // EN = 0
    __delay_ms(LCD_delay); 
}


// This Function is Use for LCD Initialize 4bit LCD Display
void LCD_in(void)
{
    LCD_command(0x02);      // 4bit LCD mode
    LCD_command(0x28);      // 4bit LCD mode 2x16 Matrix
    LCD_command(0x0E);      // Turn ON LCD with Cursor ON
    LCD_command(0x06);      // Increment after every ASCI Chare
    LCD_command(0x01);      // Refresh LCD screen
    LCD_command(0x80);      // Cursor at 0,0 position
}

/*
 * This function is use to send Data string to LCD with the
 * help of pointer.
 * 
 * pointer send data to LDC which is stored in Fleas of the MCU
 * 
 * Example of the function in code
 *   send2LCD("This is Example code");
 * 
 */
void send2LCD( char *p)
{
    while(*p != '\0')      // While until null Chare
    {
        LCD_data(*p);      // sending data with the help of pointer
        p = p+1;           // pointer increment
    }
}

#endif	/* LCD_H */

