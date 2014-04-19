
#include <p18f458.h> /* Register and bit declarations */ 
#include <delays.h>  
#include <string.h>
#include "lcd1100.h"
#pragma config OSC = HS, OSCS = OFF
#pragma config PWRT= OFF , BOR=ON, BORV = 27
#pragma config WDT = OFF
#pragma config DEBUG = OFF ,LVP =OFF , STVR =OFF


void long_to_string_lz (unsigned int input, char *str, char numdigits);
void long_to_string (unsigned int input, char *str, char numdigits);

void main (void) {
TRISD=0;
	Lcd_Init();
	Gotoxy(5,2);
	print_message("Nokia 1100 LCD ");
	Gotoxy(5,5);
	print_message("CircuitValley");
while(1) {
}
}
 					


/*
*********************************************************************************************************
* long_to_string()
*
* Description : Convert a "long" to a null-terminated string
*               (base = decimal)
* Arguments   : input = number to be converted
*               str = pointer to string (i.e. display buffer)
*               numdigits = number of digits to display
* Returns     : none
*********************************************************************************************************
*/
void long_to_string (unsigned int input, char *str, char numdigits)
{
  char digit;
  int blank = 1;
  long_to_string_lz(input, str, numdigits);
  for (digit=0; digit < numdigits-1; digit++) {
    if (str[digit] == '0') {
      if (blank == 1) str[digit] = ' ';
    }
    else {
      blank = 0;
    }
  }
}


/*
*********************************************************************************************************
* long_to_string_lz()
*
* Description : Convert a "long" to a null-terminated string, with leading zeros
*               (base = decimal)
* Arguments   : input = number to be converted
*               str = pointer to string (i.e. display buffer)
*               numdigits = number of digits to display
* Returns     : none
*********************************************************************************************************
*/
void long_to_string_lz (unsigned int input, char *str, char numdigits)
{
  char digit;
  for (digit=numdigits; digit > 0; digit--) {
    str[digit-1] = (input % 10) + '0';
    input = input / 10;
  }
  str[numdigits] = 0;    // null-terminate the string
}
