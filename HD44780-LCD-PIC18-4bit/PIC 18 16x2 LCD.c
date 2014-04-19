#pragma config OSC = HS, OSCS = OFF
#pragma config PWRT= OFF , BOR=ON, BORV = 45
#pragma config WDT = OFF
#pragma config DEBUG = OFF ,LVP =OFF , STVR =OFF
#include <p18f458.h>
#include "lcd16.h"



void main()
{

// ******Programmer :- Gaurav Chaudhary
// ****** WWW.CircuitValley.com
TRISD=0;
TRISC=0;
EN=0;
lcdinit();	
gotoXy(0,0);
prints("Hello Word!! LCD");
gotoXy(0,1);
prints("Line2 int ");
integerToLcd(4321);


while(1)
{
}
}

