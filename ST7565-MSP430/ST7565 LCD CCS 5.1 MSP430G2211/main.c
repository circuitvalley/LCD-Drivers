/*
 * File:   main.c
 * Author:  Gaurav
 * website: www.circuitvalley.com
 * Created on September 29, 2012, 1:33 AM

 *	This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.

 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.

 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.

 *	Email: mailchaduarygaurav@gmail.com

************************************************************************/


#include <msp430g2211.h>
const unsigned char font6x8[][6] =
{
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // sp
    { 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !
    { 0x00, 0x00, 0x07, 0x00, 0x07, 0x00 },   // "
    { 0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #
    { 0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $
    { 0x00, 0x62, 0x64, 0x08, 0x13, 0x23 },   // %
    { 0x00, 0x36, 0x49, 0x55, 0x22, 0x50 },   // &
    { 0x00, 0x00, 0x05, 0x03, 0x00, 0x00 },   // '
    { 0x00, 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (
    { 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )
    { 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *
    { 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +
    { 0x00, 0x00, 0x00, 0x50, 0x30, 0x00 },   // ,
    { 0x00, 0x08, 0x08, 0x08, 0x08, 0x08 },   // -
    { 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 },   // .
    { 0x00, 0x20, 0x10, 0x08, 0x04, 0x02 },   // /
    { 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 0
    { 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 1
    { 0x00, 0x42, 0x61, 0x51, 0x49, 0x46 },   // 2
    { 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 3
    { 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 4
    { 0x00, 0x27, 0x45, 0x45, 0x45, 0x39 },   // 5
    { 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 6
    { 0x00, 0x01, 0x71, 0x09, 0x05, 0x03 },   // 7
    { 0x00, 0x36, 0x49, 0x49, 0x49, 0x36 },   // 8
    { 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E },   // 9
    { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00 },   // :
    { 0x00, 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;
    { 0x00, 0x08, 0x14, 0x22, 0x41, 0x00 },   // <
    { 0x00, 0x14, 0x14, 0x14, 0x14, 0x14 },   // =
    { 0x00, 0x00, 0x41, 0x22, 0x14, 0x08 },   // >
    { 0x00, 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?
    { 0x00, 0x32, 0x49, 0x59, 0x51, 0x3E },   // @
    { 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C },   // A
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C
    { 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F
    { 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G
    { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H
    { 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I
    { 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J
    { 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K
    { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L
    { 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M
    { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P
    { 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q
    { 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R
    { 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 },   // S
    { 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T
    { 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U
    { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V
    { 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W
    { 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 },   // X
    { 0x00, 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y
    { 0x00, 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z
    { 0x00, 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [
    { 0x00, 0x04, 0x08, 0x10, 0x20, 0x40  },   // /
    { 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]
    { 0x00, 0x04, 0x02, 0x01, 0x02, 0x04 },   // ^
    { 0x00, 0x40, 0x40, 0x40, 0x40, 0x40 },   // _
    { 0x00, 0x00, 0x01, 0x02, 0x04, 0x00 },   // '
    { 0x00, 0x20, 0x54, 0x54, 0x54, 0x78 },   // a
    { 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x20 },   // c
    { 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F },   // d
    { 0x00, 0x38, 0x54, 0x54, 0x54, 0x18 },   // e
    { 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f
    { 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C },   // g
    { 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h
    { 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i
    { 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00 },   // j
    { 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k
    { 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l
    { 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x38 },   // o
    { 0x00, 0xFC, 0x24, 0x24, 0x24, 0x18 },   // p
    { 0x00, 0x18, 0x24, 0x24, 0x18, 0xFC },   // q
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r
    { 0x00, 0x48, 0x54, 0x54, 0x54, 0x20 },   // s
    { 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t
    { 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u
    { 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v
    { 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w
    { 0x00, 0x44, 0x28, 0x10, 0x28, 0x44 },   // x
    { 0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C },   // y
    { 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44 },   // z
    { 0x00, 0x08, 0x36, 0x41, 0x41, 0x00 },   // {
    { 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00 },	  // |
    { 0x00, 0x41, 0x41, 0x36, 0x08, 0x00 },   // }
    { 0x00, 0x02, 0x04, 0x02, 0x01, 0x02 }    // ~
};

#define LCD_DATA 0x00

#define CMD_DISPLAY_OFF   0xAE
#define CMD_DISPLAY_ON    0xAF

#define CMD_SET_DISP_START_LINE  0x40
#define CMD_SET_PAGE  0xB0

#define CMD_SET_COLUMN_UPPER  0x10
#define CMD_SET_COLUMN_LOWER  0x00

#define CMD_SET_ADC_NORMAL  0xA0
#define CMD_SET_ADC_REVERSE 0xA1

#define CMD_SET_DISP_NORMAL 0xA6
#define CMD_SET_DISP_REVERSE 0xA7

#define CMD_SET_ALLPTS_NORMAL 0xA4
#define CMD_SET_ALLPTS_ON  0xA5
#define CMD_SET_BIAS_9 0xA2
#define CMD_SET_BIAS_7 0xA3

#define CMD_RMW  0xE0
#define CMD_RMW_CLEAR 0xEE
#define CMD_INTERNAL_RESET  0xE2
#define CMD_SET_COM_NORMAL  0xC0
#define CMD_SET_COM_REVERSE  0xC8
#define CMD_SET_POWER_CONTROL  0x28
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLUME_FIRST  0x81
#define  CMD_SET_VOLUME_SECOND  0
#define CMD_SET_STATIC_OFF  0xAC
#define  CMD_SET_STATIC_ON  0xAD
#define CMD_SET_STATIC_REG  0x0
#define CMD_SET_BOOSTER_FIRST  0xF8
#define CMD_SET_BOOSTER_234  0
#define  CMD_SET_BOOSTER_5  1
#define  CMD_SET_BOOSTER_6  3
#define CMD_NOP  0xE3
#define CMD_TEST  0xF0

void lcdClr(void);
void goHome(void);
void lcdRow(unsigned char r);
void lcdCol(unsigned char c);
void prints( char* s);
void gotoXy(unsigned char , unsigned char);
void printc(unsigned char r);
void doSPI(unsigned char );

void write_buffer(unsigned char* buffer);
void sendData(unsigned char data);
void sendCmd(unsigned char cmd);


#define LCDPORT P1OUT
#define GND BIT0
#define VCC BIT1
#define A0 	BIT2
#define CS	BIT3
#define SCK BIT4
#define SDA BIT5
#define RST BIT6

void main(void) {
	
	WDTCTL = WDTPW + WDTHOLD;	// Stop WDT
	  P1DIR = 0xFF;
	  LCDPORT &= ~GND;
	  LCDPORT |= VCC;
	  LCDPORT &= ~RST;
	  __delay_cycles(1000);
	  LCDPORT |= RST;


		LCDPORT &=~A0;
		LCDPORT &=~CS;
		doSPI(CMD_SET_BIAS_7);

		doSPI(CMD_SET_ADC_NORMAL);
		doSPI(CMD_SET_COM_NORMAL);
		doSPI(CMD_SET_DISP_START_LINE);

		doSPI(CMD_SET_POWER_CONTROL | 0x4 );
		 __delay_cycles(1000);
		doSPI(CMD_SET_POWER_CONTROL | 0x7);

		 __delay_cycles(1000);


		doSPI(CMD_DISPLAY_ON);


		doSPI(CMD_SET_ALLPTS_NORMAL);

		lcdClr();
		gotoXy(0,20);
		prints("ST7565 Display");
		gotoXy(2,20);
		prints("SPI interface");
		gotoXy(4,20);
		prints("MSP430G2211");

			while (1){}
	}


	void lcdClr(void){
	 unsigned char i, j;

	  for(i = 0; i < 8; i++) {

	     sendCmd(0xB0 | i); //sets page(row) from 0 to 7
		 sendCmd(0x10);				//sets column address(MSB) to 0 for each page(row)
	     sendCmd(0x00);				//sets Column address(LSB)to 0 for each page(row)

	    for(j = 0; j < 132; j++) {
		sendData(0x00);
	    }

	  }
	}




	void printc(unsigned char r)
	{
		char i;
		for ( i = 0; i < 6; i++ ){
		sendData(font6x8[r - 32][i] );
		        }

		//doSPI(LCD_DATA | 0); // 1px gap after each letter

	}


	void sendData(unsigned char data)
	{
		LCDPORT |=A0;
			doSPI(data);
	}
	void sendCmd(unsigned char cmd)
	{
		LCDPORT &=~A0;
			doSPI(cmd);
	}
/*
	void printnummega(unsigned char x, unsigned char y,unsigned char n)
	{
	unsigned char i;
	gotoXy(x,y);
	for(i=0;i<15;i++)
	{
		sendData(nummega[n][0][i] );
	}

	gotoXy(x+1,y);
	for(i=0;i<15;i++)
	{
		sendData(nummega[n][1][i] );
	}

	gotoXy(x+2,y);
	for(i=0;i<15;i++)
	{
		sendData(nummega[n][2][i] );
	}
	}*/

	void doSPI(unsigned char d)
	{


		unsigned char i;
		for(i = 0; i< 8; i++)
		{
			LCDPORT &=~SDA;

			if(d & 0x80)
			{
				LCDPORT |=SDA;

			}

			LCDPORT &=~SCK;
			LCDPORT |=SCK;


			d <<= 1;


		}

	}


	void write_buffer(unsigned char *buffer) {
	  unsigned char c, p;

	  for(p = 0; p < 8; p++) {
		gotoXy(p,0); //row , column
	    for(c = 0; c < 132; c++) {
	     sendData(buffer[(128*p)+c]);
	    }
	  }

	}




	void setpixel(unsigned char *buff, unsigned char x, unsigned char y) {
	     buff[((y/8)*128)+x] |=  0x01<<(y%8);
	}



	// the most basic function, clear a single pixel
	void clearpixel(unsigned char *buff, unsigned char x, unsigned char y) {
	  // x is which column
	  buff[x+ (y/8)*128] &= ~(0x01<<(y%8));
	}

	/*/ bresenham's algorithm - thx wikpedia
	void drawline(unsigned char *buff,unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1) {
	 unsigned char temp;
	  unsigned char steep = (y1 - y0) > (x1 - x0);

	  if (steep) {
	    temp=x0;
		x0 = y0;
		y0 = temp;

	    temp=x1;
		x1 = y1;
		y1 = temp;

	  }

	  if (x0 > x1) {
	     temp=x0;
		x0 = x1;
		x1 = temp;

	     temp=y0;
		y0 = y1;
		y1 = temp;
	;
	  }

	  unsigned char dx, dy;
	  dx = x1 - x0;
	  dy = (y1 - y0);

	   char err = dx / 2;
	   char ystep;

	  if (y0 < y1) {
	    ystep = 1;
	  } else {
	    ystep = -1;}

	  for (; x0<x1; x0++) {
	    if (steep) {
	      setpixel(buff, y0, x0);
	    } else {
	      setpixel(buff, x0, y0);
	    }
	    err -= dy;
	    if (err < 0) {
	      y0 += ystep;
	      err += dx;
	    }
	  }
	}*/

	// filled rectangle
	void fillrect(unsigned char *buff,unsigned char x, unsigned char y, unsigned char w, unsigned char h) {
	unsigned char i,j;
	  // stupidest version - just pixels - but fast with internal buffer!
	  for (i=x; i<x+w; i++) {
	    for ( j=y; j<y+h; j++) {
	      setpixel(buff, i, j);
	    }
	  }
	}


	// draw a rectangle
	void drawrect(unsigned char *buff,unsigned char x, unsigned char y, unsigned char w, unsigned char h) {
	unsigned char i;
	  // stupidest version - just pixels - but fast with internal buffer!

	  for ( i=x; i<x+w; i++) {
	    setpixel(buff, i, y);
	    setpixel(buff, i, y+h-1);
	  }


	  for ( i=y; i<y+h; i++) {
	    setpixel(buff, x, i);
	    setpixel(buff, x+w-1, i);
	  }

	}

/*
	// draw a circle
	void drawcircle(unsigned char *buff,unsigned char x0, unsigned char y0, unsigned char r ) {
	  char f = 1 - r;
	  char ddF_x = 1;
	  char ddF_y = -2 * r;
	  char x = 0;
	  char y = r;

	  setpixel(buff, x0, y0+r);
	  setpixel(buff, x0, y0-r);
	  setpixel(buff, x0+r, y0);
	  setpixel(buff, x0-r, y0);

	  while (x<y) {
	    if (f >= 0) {
	      y--;
	      ddF_y += 2;
	      f += ddF_y;
	    }
	    x++;
	    ddF_x += 2;
	    f += ddF_x;

	    setpixel(buff, x0 + x, y0 + y);
	    setpixel(buff, x0 - x, y0 + y);
	    setpixel(buff, x0 + x, y0 - y);
	    setpixel(buff, x0 - x, y0 - y);

	    setpixel(buff, x0 + y, y0 + x);
	    setpixel(buff, x0 - y, y0 + x);
	    setpixel(buff, x0 + y, y0 - x);
	    setpixel(buff, x0 - y, y0 - x);

	  }
	}*/


	/*/ draw a circle
	void fillcircle(unsigned char *buff,
		      unsigned char x0, unsigned char y0, unsigned char r,
		      unsigned char color) {
	 char f = 1 - r;
	 char ddF_x = 1;
	  char ddF_y = -2 * r;
	  char x = 0;
	  char y = r;
	unsigned char i;
	  for (i=y0-r; i<=y0+r; i++) {
	    setpixel(buff, x0, i);
	  }

	  while (x<y) {
	    if (f >= 0) {
	      y--;
	      ddF_y += 2;
	      f += ddF_y;
	    }
	    x++;
	    ddF_x += 2;
	    f += ddF_x;

	    for (i=y0-y; i<=y0+y; i++) {
	      setpixel(buff, x0+x, i);
	      setpixel(buff, x0-x, i);
	    }
	    for ( i=y0-x; i<=y0+x; i++) {
	      setpixel(buff, x0+y, i);
	      setpixel(buff, x0-y, i);
	    }
	  }
	}*/


	// clear everything
	void clearBuffer(unsigned char *buff) {


	unsigned int i;

	for (i=0;i<1056;i++)
	{
	buff[i]= 0x00;
	}
	}







	void goHome(void)
	{
		sendCmd(0xB0); 	//sets page(row) to 0
		sendCmd(0x10);	//sets column to 0
		sendCmd(0x00);
	}

	void lcdRow(unsigned char r)
	{
		sendCmd(0xB0 | (r & 0x0F));
	}

	void lcdCol(unsigned char c)
	{	sendCmd(0x10 | (c>>4)); // Sets the DDRAM column addr - upper 3-bit
	    doSPI(0x00 | (c & 0x0F)); // lower 4-bit
	}

	// gotoXy(Row , column ) , row-> max 8 , column->95
	void gotoXy(unsigned char x,unsigned char y)
	{
		sendCmd(0xB0|(x & 0x0F));

		sendCmd(0x10|((y>>4)));
		sendCmd(0x00|(y & 0x0F));
	}

	void prints(char* s)
	{

		while(*s)
		{
			printc(*s++);
		}
	}

