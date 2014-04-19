#ifndef __lcd16_h_
#define __lcd16_h_

#include <p18f458.h>

#define RS PORTDbits.RD5
#define EN PORTDbits.RD7

void integerToLcd(int integer );
void gotoXy(unsigned char  ,unsigned char );
void lcdinit(void);
void lcdcmd(unsigned char);
void lcdData(unsigned char);
void waitlcd(int);
void prints(const rom char * message);
#endif