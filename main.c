/*
 * File:   main.c
 * Author: Rishekesh R Das
 *
 * Created on September 6, 2022, 1:53 PM
 */

#define _XTAL_FREQ 8000000UL
#include <xc.h>
#include "LCD_4bit.h"

void main(void) 
{
    DDRC = 0x00;
    LCD_in();
    send2LCD("LCD in interface Compleat ");
    while(1)
    {
       /*
        *  Put Your code hear
        */ 
    }
   
}
