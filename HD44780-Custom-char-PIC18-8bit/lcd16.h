#ifndef __lcd16_h_
#define __lcd16_h_

#include <p18F458.h>

#define RS PORTCbits.RC0
#define EN PORTCbits.RC1


void gotoXy(unsigned char  ,unsigned char );
void lcdInit(void);
void lcdCmd(unsigned char);
void lcdData(unsigned char);
void lcdWriteNibble(unsigned char);
void waitLcd(unsigned char);
void prints(rom const char * message);
#endif