
#include <p18f458.h>
#include <delays.h> 
#include <string.h>

// set output pins for lcd here
#define sclk 	PORTDbits.RD4
#define sda 	PORTDbits.RD5
#define cs 		PORTDbits.RD6
#define rst 	PORTDbits.RD7

#define CMD		0
#define DATA	1


void Lcd_Init(void);
void spi(char cd,unsigned char myData);
void Lcd_Clear(void);
void SetX(char x);
void SetY(char y);
void Gotoxy(char x,char y);
void VLine(char x,char y,char on);
void Line(unsigned char x,unsigned char y,unsigned char y2,unsigned char on);
void print_message(const rom char* message);
void print_char(char c);
void print_string(char * message);
