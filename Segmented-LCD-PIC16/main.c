/* 
 * File:   main.c
 * Author: Gaurav
 * Compny:www.CircuitValley.com
 * Complier: - HI-TECH PRO 9.82
 *  * Created on February 14, 2012, 9:39 PM
 */

#include <pic.h>
#include "lcdmap.h"

//set internal oscillator , watch dog off, power up timer off, mclre pin as mclre, burnout off
__CONFIG( FOSC_INTOSCIO & WDTE_OFF & PWRTE_OFF  & MCLRE_ON  & BOREN_OFF  & IESO_OFF & FCMEN_OFF );

void displayNumber(unsigned char Position, unsigned char Number);
void initLcd(void);
/*
 * 
 */
void main() {
   
   OSCCON =0x7C;   //set internal oscillator to 8mhz
   initLcd();
   
   D2DOT =1;    //set dot of digit 2 to on
   D3DOT =1;    //set dot of digit 3 to on
   D4DOT =1;
   
    displayNumber(1,2);     //put number 2 on digit 1
    displayNumber(2,3);     //put number 3 on digit2
    displayNumber(3,4);
    displayNumber(4,5);
    while (1)
    {
 
       
    }
}
void initLcd(void)
{
    LCDPS=0x39;     // lcd presaclaer set to 1/10 of LCD clock  (clock source set by the lcdcon register)
                    //LCD Type (like one , two ,three or four common) we set it to 4 common  """"you have to set the same thing in th LCDCON register too
                    // LCD driver module Status bit (active or disabled)
                    // writing to LCDDATA register is enabled


    LCDSE0 = 0xFF;  //LCD segment PINS from SEG0 to SEG 7 works as SEGMENT (NOT a digital i/o)
    LCDSE1 = 0x01;  //LCD segment SEG8 works as segment pin (not an digital i/o) ( THE LOW Battery symbol is on this segment which is not shown in the schematic)

    LCDCON=0x9F;    //SET lcd driver moudule to active
                    //LCD drive enabled even in the sleep mode
                    //LCD bias voltage pins are enabled (THE VLCD pins """"CAUTION:::: THE VLCD pins play a vital role is the contrast of the lcd"""")
                    //LCD clock source to LF 31khz oscillator
                    //LCD Type (like one , two ,three or four common) we set it to 4 common
    LCDDATA0 = 0;   //all pixals off
    LCDDATA1 = 0;
    LCDDATA2 = 0;
    LCDDATA3 = 0;
    LCDDATA4 = 0;
    LCDDATA5 = 0;
    LCDDATA6 = 0;
    LCDDATA7 = 0;
    LCDDATA8 = 0;
    LCDDATA9 = 0;
    LCDDATA10 =0;
    LCDDATA11 =0;   //all pixals off
}
void displayNumber(unsigned char Position, unsigned char Number){

	switch(Position){
	case 1:
		D1A = D1B = D1C = D1D = D1E = D1F = D1G = 0; //intialize cleared
		switch(Number){
		case 1:
			D1B = D1C = 1;          // these pixal defination are in the lcdmap.h you may need to chage them according to you lcd pins and pixal allignment
			break;
		case 2:
			D1A = D1B = D1G = D1E = D1D = 1;
			break;
		case 3:
			D1A = D1B = D1G = D1C = D1D = 1;
			break;
		case 4:
			D1F = D1G = D1B = D1C = 1;
			break;
		case 5:
			D1A = D1F = D1G = D1C = D1D = 1;
			break;
		case 6:
			D1A = D1F = D1E = D1D = D1C = D1G = 1;
			break;
		case 7:
			D1A = D1B = D1C = 1;
			break;
		case 8:
			D1A = D1B = D1C = D1D = D1E = D1F = D1G = 1;
			break;
		case 9:
			D1A = D1B = D1C = D1D = D1F = D1G = 1;
			break;
                case 10:
                        D1A = D1B = D1C = D1E = D1F = D1G =1;
                        break;
                case 11:
                        D1C = D1D = D1E = D1F = D1G =1;
                        break;
                case 12:
                        D1A = D1D = D1E = D1F =1;
                        break;
                case 13:
                        D1B = D1C = D1D =D1E = D1G =1;
                        break;
                case 14:
                        D1A = D1D = D1E = D1F = D1G =1;
                        break;
                case 15:
                        D1A = D1E = D1F = D1G =1;
                        break;
		case 0:
			D1A = D1B = D1C = D1D = D1E = D1F = 1;
			break;
		}
		break;
	case 2:
		D2A = D2B = D2C = D2D = D2E = D2F = D2G = 0; //intialize cleared
		switch(Number){

		case 1:
			D2B = D2C = 1;
			break;
		case 2:
			D2A = D2B = D2G = D2E = D2D = 1;
			break;
		case 3:
			D2A = D2B = D2G = D2C = D2D = 1;
			break;
		case 4:
			D2F = D2G = D2B = D2C = 1;
			break;
		case 5:
			D2A = D2F = D2G = D2C = D2D = 1;
			break;
		case 6:
			D2A = D2F = D2E = D2D = D2C = D2G = 1;
			break;
		case 7:
			D2A = D2B = D2C = 1;
			break;
		case 8:
			D2A = D2B = D2C = D2D = D2E = D2F = D2G = 1;
			break;
		case 9:
			D2A = D2B = D2C = D2D = D2F = D2G = 1;
			break;
                case 10:
                        D2A = D2B = D2C = D2E = D2F = D2G =1;
                        break;
                case 11:
                        D2C = D2D = D2E = D2F = D2G =1;
                        break;
                case 12:
                        D2A = D2D = D2E = D2F =1;
                        break;
                case 13:
                        D2B = D2C = D2D = D2E = D2G =1;
                        break;
                case 14:
                        D2A = D2D = D2E = D2F = D2G =1;
                        break;
                case 15:
                        D2A = D2E = D2F = D2G =1;
                        break;
		case 0:
			D2A = D2B = D2C = D2D = D2E = D2F = 1;
			break;
		}
		break;
	case 3:
		D3A = D3B = D3C = D3D = D3E = D3F = D3G = 0; //intialize cleared
		switch(Number){
		case 1:
			D3B = D3C = 1;
			break;
		case 2:
			D3A = D3B = D3G = D3E = D3D = 1;
			break;
		case 3:
			D3A = D3B = D3G = D3C = D3D = 1;
			break;
		case 4:
			D3F = D3G = D3B = D3C = 1;
			break;
		case 5:
			D3A = D3F = D3G = D3C = D3D = 1;
			break;
		case 6:
			D3A = D3F = D3E = D3D = D3C = D3G = 1;
			break;
		case 7:
			D3A = D3B = D3C = 1;
			break;
		case 8:
			D3A = D3B = D3C = D3D = D3E = D3F = D3G = 1;
			break;
		case 9:
			D3A = D3B = D3C = D3D = D3F = D3G = 1;
			break;
                case 10:
                        D3A = D3B = D3C = D3E = D3F = D3G =1;
                        break;
                case 11:
                        D3C = D3D = D3E = D3F = D3G =1;
                        break;
                case 12:
                        D3A = D3D =  D3E = D3F =1;
                        break;
                case 13:
                        D3B = D3C = D3D = D3E = D3G =1;
                        break;
                case 14:
                        D3A = D3D = D3E = D3F = D3G =1;
                        break;
                case 15:
                        D3A = D3E = D3F = D3G =1;
                        break;
		case 0:
			D3A = D3B = D3C = D3D = D3E = D3F = 1;
			break;
		}
		break;
	case 4:
		D4A = D4B = D4C = D4D = D4E = D4F = D4G = 0; //intialize cleared
		switch(Number){
		case 1:
			D4B = D4C = 1;
			break;
		case 2:
			D4A = D4B = D4G = D4E = D4D = 1;
			break;
		case 3:
			D4A = D4B = D4G = D4C = D4D = 1;
			break;
		case 4:
			D4F = D4G = D4B = D4C = 1;
			break;
		case 5:
			D4A = D4F = D4G = D4C = D4D = 1;
			break;
		case 6:
			D4A = D4F = D4E = D4D = D4C = D4G = 1;
			break;
		case 7:
			D4A = D4B = D4C = 1;
			break;
		case 8:
			D4A = D4B = D4C = D4D = D4E = D4F = D4G = 1;
			break;
		case 9:
			D4A = D4B = D4C = D4D = D4F = D4G = 1;
			break;
                case 10:
                        D4A = D4B = D4C =D4E = D4F = D4G =1;
                        break;
                case 11:
                        D4C = D4D = D4E = D4F = D4G =1;
                        break;
                case 12:
                        D4A = D4D = D4E = D4F =1;
                        break;
                case 13:
                        D4B = D4C = D4D = D4E = D4G =1;
                        break;
                case 14:
                        D4A = D4D = D4E = D4F = D4G =1;
                        break;
                case 15:
                        D4A = D4E = D4F = D4G =1;
                        break;
		case 0:
			D4A = D4B = D4C = D4D = D4E = D4F = 1;
			break;
		}
                break;
	}
}
