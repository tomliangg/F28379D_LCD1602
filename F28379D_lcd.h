/*
 *	F28379D_lcd.h
 *	Support C2000 Delfino LAUNCHXL-F28379D
 *
 *  Created on: June 27, 2017
 *  Author: Tom Liang
 *	Version: 1.0
 *	Acknowledgement: thanks to Mani for the project insight
 */
 
/*
||     F28379D Pin          <==>      LCD1602/ADM1602K Pin      
||         GND              <==>         Pin1 (Vss)
||         5V/Vcc           <==>         Pin2 (VDD 5V)
||         GND              <==>         Pin3 (connect a 3.9k to GND) 
||         GPIO4/P36        <==>         Pin4  (RS)
||         GND		        <==>         Pin5  (R/W, To GND is only enable to write)
||         GPIO5/P35        <==>         Pin6  (E)
||         GPIO6/P80        <==>         Pin7
||         GPIO7/P79        <==>         Pin8
||         GPIO8/P78        <==>         Pin9
||         GPIO9/P77        <==>         Pin10
||         GPIO10/P76       <==>         Pin11
||         GPIO11/P75       <==>         Pin12
||         GPIO14/P74       <==>         Pin13
||         GPIO15/P73       <==>         Pin14                    
||         5V/Vcc           <==>         Pin15,  (A, connect a 330R to Vcc)
||         GND              <==>         Pin16,  (K, connect to GND)
*/



void CursorON(void);							  /* Make Cursor visible */
void CursorOFF(void);							  /* Hide cursor */
void DisplayLCD(char LineNumber,char *Message);	  /* Display the given message (16 characters) at given location on LCD */
void WriteCommandLCD(unsigned char CommandByte);  /* Write the given command to LCD */
void WriteDataLCD(unsigned char DataByte);		  /* Write the given data to LCD */
void InitializeLCD(void);						  /* Initialize LCD */

void Gpio_setup1(void);							  /* Initialize GPIO pins 4-11, 14-15 */
void LCDDelay(void);							  /* 50us delay */
void LCDDelay1600(void);						  /* 1600us delay */
void SendByte(unsigned char Value);				  /* Send a byte of data to LCD */




