#include "lcd16.h"

void lcdCmd(unsigned char Data)
{

EN=0;
PORTB =Data ;
RS=0; //because sending command
waitLcd(0x2);
EN=1;
EN=0;

}


void lcdData(unsigned char l)
{
EN=0;
PORTB =l ;
RS=1;  //because sending data
waitLcd(0x2);
EN=1;
EN=0;
}

void lcdInit(void)
{
RS=0;
EN=0;
PORTB= 0x30;
waitLcd(40);
EN=1;
EN=0;
waitLcd(5);
EN=1;
EN=0;
waitLcd(5);
EN=1;
EN=0;
waitLcd(2);
PORTB=20;
EN=1;
EN=0;
lcdCmd(0x38);   //set data length 8 bit 2 line
waitLcd(250); 
lcdCmd(0x0E);   // set display on cursor on blink on
waitLcd(250);
lcdCmd(0x01); // clear lcd 
waitLcd(250);
lcdCmd(0x06);  // cursor shift direction
waitLcd(250);
lcdCmd(0x80);  //set ram address
waitLcd(250);
}

void waitLcd(unsigned char x)
{
unsigned char i;
for (x ;x>1;x--)
{
for (i=0;i<=110;i++);
}
}



//gotoXy(column, row);
void gotoXy(unsigned char  x,unsigned char y)
{
 if(x<40)
 {
  if(y) x|=0b01000000;
  x|=0b10000000;
  lcdCmd(x);
  }
}





void prints(rom const char * message){	// Write message to LCD (C string type)
lcdCmd(0x8); // disable display;
		while (*message){			// Look for end of string
					lcdData(*message++);
					}
	lcdCmd(0xE); // enable display;
	}






void clearLcd(void)
{
	//	Send command to LCD (0x01)
	lcdCmd(0x01);	
}

