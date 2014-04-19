// ******Programmer :- Gaurav Chaudhary
// ****** WWW.CircuitValley.com
#include "lcd16.h"

void lcdcmd(unsigned char Data)
{
RS=0; //because sending command
EN=0;
PORTC =((Data >> 4) & 0x0F);
EN=1;
waitlcd(2);
EN=0;
PORTC  = (Data & 0x0F);

EN =1;
waitlcd(2);
EN=0;


}
void lcdData(unsigned char l)
{
RS=1;  //because sending data
EN=0;
PORTC =((l >> 4) & 0x0F);

EN=1;
waitlcd(2);
EN=0;
PORTC  = (l & 0x0F);
EN=1;
waitlcd(2);
EN=0;



}

void lcdinit(void)
{
RS=0;
EN=0;
PORTC= 0x3;
waitlcd(40);
EN=1;
EN=0;
waitlcd(5);
EN=1;
EN=0;
waitlcd(5);
EN=1;
EN=0;
waitlcd(2);
PORTC=2;
EN=1;
EN=0;
lcdcmd(0x28);   //set data length 4 bit 2 line
waitlcd(250); 
lcdcmd(0x0E);   // set display on cursor on blink on
waitlcd(250);
lcdcmd(0x01); // clear lcd 
waitlcd(250);
lcdcmd(0x06);  // cursor shift direction
waitlcd(250);
lcdcmd(0x80);  //set ram address
waitlcd(250);
}

void waitlcd(int x)
{
int i;
for (x ;x>1;x--)
{
for (i=0;i<=110;i++);
}
}




void gotoXy(unsigned char  x,unsigned char y)
{
 if(x<40)
 {
  if(y) x|=0b01000000;
  x|=0b10000000;
  lcdcmd(x);
  }
}





void prints(const rom char * message){	// Write message to LCD (C string type)
lcdcmd(0x8); // disable display;
		while (*message){			// Look for end of string
					lcdData(*message++);
					}
	lcdcmd(0xE); // enable display;
	}




void integerToLcd(int integer )
{
	//	Break down the original number into the thousands, hundreds, tens,
	//	and ones places and then immediately write that value to the LCD
unsigned char thousands	,hundreds,tens,ones;
thousands = integer / 1000;
	
    lcdData(thousands + 0x30);
	
	 hundreds = ((integer - thousands*1000)-1) / 100;

	lcdData( hundreds + 0x30);
tens=(integer%100)/10;	

	lcdData( tens + 0x30);
	ones=integer%10;

	lcdData( ones + 0x30);
}


void clearLcd(void)
{
	//	Send command to LCD (0x01)
	lcdcmd(0x01);	
}

