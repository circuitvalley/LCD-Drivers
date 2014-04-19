/* 
 * File:   main.c
 * Author: Gaurav
 *
 * Created on February 10, 2012, 12:09 AM
 */

#pragma config OSC = HS, OSCS = OFF
#pragma config PWRT= OFF , BOR=ON, BORV = 27
#pragma config WDT = OFF
#pragma config DEBUG = OFF ,LVP =OFF , STVR =OFF
#include <p18f458.h>
#include "lcd16.h"

/*
 * 
 */
void main() {
    TRISB=0x00;
    TRISC=0x00;
    lcdInit();
    gotoXy(0,0);
prints("custom font");


lcdCmd(0x40);
lcdData(0xe);
lcdData(0x1b);
lcdData(0x11);
lcdData(0x11);
lcdData(0x11);
lcdData(0x11);
lcdData(0x11);
lcdData(0x1f);

lcdData(0xe);
lcdData(0x1b);
lcdData(0x11);
lcdData(0x11);
lcdData(0x11);
lcdData(0x11);
lcdData(0x1F);
lcdData(0x1f);

lcdData(0xe);
lcdData(0x1b);
lcdData(0x11);
lcdData(0x11);
lcdData(0x11);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1f);

lcdData(0xe);
lcdData(0x1b);
lcdData(0x11);
lcdData(0x11);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1f);

lcdData(0xe);
lcdData(0x1b);
lcdData(0x11);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1f);

lcdData(0xe);
lcdData(0x1b);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1f);

lcdData(0xe);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1F);
lcdData(0x1f);




gotoXy(0,1);

lcdData(0x00);
lcdData(0x01);
lcdData(0x02);
lcdData(0x03);
lcdData(0x04);
lcdData(0x05);
lcdData(0x06);
prints(" BATTERY ");
    while(1)
    {}
}

