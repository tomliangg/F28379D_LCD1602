/*
 *	F28379D_lcd.c
 *	Support C2000 Delfino LAUNCHXL-F28379D
 *
 *  Created on: June 27, 2017
 *  Author: Tom Liang
 *	Version: 1.0
 *	Acknowledgement: thanks to Mani for the project insight
 */
 
 //include files
 #include "F28x_Project.h"
 #include "F28379D_lcd.h"
 
 // Gpio_setup1 - configure pins as GPIO output, enable pullup
void Gpio_setup1(void)
{
   EALLOW;

   // Enable GPIO as output pins on GPIO4 - GPIO11, GPIO14 - GPIO15; see page 989 for the detailed description of the register
   GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;  // Enable pullup on GPIO4/P36
   GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0; // GPIO4 = GPIO4
   GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;   // GPIO4 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;  // Enable pullup on GPIO5/P35
   GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0; // GPIO5 = GPIO5
   GpioCtrlRegs.GPADIR.bit.GPIO5 = 1;   // GPIO5 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;  // Enable pullup on GPIO6/P80
   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0; // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;   // GPIO6 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;  // Enable pullup on GPIO7/P79
   GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0; // GPIO7 = GPIO7
   GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;   // GPIO5 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;   // Enable pullup on GPIO8/P78
   GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;  // GPIO8 = GPIO8
   GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;   // GPIO8 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;   // Enable pullup on GPIO9/P77
   GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;  // GPIO9 = GPIO9
   GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;   // GPIO9 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;  // Enable pullup on GPIO10/P76
   GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0; // GPIO10 = GPIO10
   GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;   // GPIO10 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;  // Enable pullup on GPIO11/P75
   GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0; // GPIO11 = GPIO11
   GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;   // GPIO11 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;  // Enable pullup on GPIO14/P74
   GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0; // GPIO14 = GPIO14
   GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;   // GPIO14 = output

   GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;  // Enable pullup on GPIO15/P73
   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0; // GPIO15 = GPIO15
   GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;   // GPIO15 = output

   EDIS;
}

/* Initializes LCD */
void InitializeLCD(void)
{
    EALLOW;

    GpioDataRegs.GPASET.bit.GPIO5 = 1;   // Enable LCD module by set E/Set GPIO5
    LCDDelay1600();

    WriteCommandLCD(0x38);          //Command to select 8 bit interface
    LCDDelay1600();

    WriteCommandLCD(0x08);          //Command to off cursor,display off
    WriteCommandLCD(0x01);          //Command to Clear LCD
    LCDDelay1600();
    WriteCommandLCD(0x06);          //Command for setting entry mode

    WriteCommandLCD(0x0f);          //Command to on cursor,blink cursor
    WriteCommandLCD(0x02);          //Command return the cursor to home
    LCDDelay1600();

    EDIS;
}

/* Writes a command byte to LCD */
void WriteCommandLCD(unsigned char CommandByte)
{
    EALLOW;
    GpioDataRegs.GPACLEAR.bit.GPIO4 = 1; //Clear RS pin to write command/clear GPIO4
    SendByte(CommandByte);
    LCDDelay();                     //Small delay
    EDIS;
}

/* Send a byte of data to LCD */
void SendByte(unsigned char Value)
{
    unsigned char temp;
    EALLOW;

    if((Value & 0x01) == 0x01)
        GpioDataRegs.GPASET.bit.GPIO6 = 1;  //set D0
    else
        GpioDataRegs.GPACLEAR.bit.GPIO6 = 1; //clear D0


    if((Value & 0x02) == 0x02)
        GpioDataRegs.GPASET.bit.GPIO7 = 1;  //set D1
    else
        GpioDataRegs.GPACLEAR.bit.GPIO7 = 1; //clear D1


    if((Value & 0x04) == 0x04)
        GpioDataRegs.GPASET.bit.GPIO8 = 1;  //set D2
    else
        GpioDataRegs.GPACLEAR.bit.GPIO8 = 1; //clear D2

    if((Value & 0x08) == 0x08)
        GpioDataRegs.GPASET.bit.GPIO9 = 1;  //set D3
    else
        GpioDataRegs.GPACLEAR.bit.GPIO9 = 1; //clear D3

    if((Value & 0x10) == 0x10)
        GpioDataRegs.GPASET.bit.GPIO10 = 1;  //set D4
    else
        GpioDataRegs.GPACLEAR.bit.GPIO10 = 1; //clear D4

    if((Value & 0x20) == 0x20)
        GpioDataRegs.GPASET.bit.GPIO11 = 1;  //set D5
    else
        GpioDataRegs.GPACLEAR.bit.GPIO11 = 1; //clear D5


    if((Value & 0x40) == 0x40)
        GpioDataRegs.GPASET.bit.GPIO14 = 1;  //set D6
    else
        GpioDataRegs.GPACLEAR.bit.GPIO14 = 1; //clear D6


    if((Value & 0x80) == 0x80)
        GpioDataRegs.GPASET.bit.GPIO15 = 1;  //set D7
    else
        GpioDataRegs.GPACLEAR.bit.GPIO15 = 1; //clear D7


    GpioDataRegs.GPASET.bit.GPIO5 = 1;   // set E pin to select LCD
    for(temp=0;temp<5; temp++);
    GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;   //Clear E pin to deselect LCD
    LCDDelay();                         //Small delay

    EDIS;
}

/* Writes a Data byte to LCD */
void WriteDataLCD(unsigned char DataByte)
{
    EALLOW;
    GpioDataRegs.GPASET.bit.GPIO4 = 1; //Set RS pin to 1 to write Data
    SendByte(DataByte);
    LCDDelay();                         //Small delay
    EDIS;
}

/* Small delay */
void LCDDelay(void)
{
    DELAY_US(50);
}

/* Big delay */
void LCDDelay1600(void)
{
    DELAY_US(1600);
}

/* Makes cursor visible */
void CursorON(void)
{
    WriteCommandLCD(0x0f);          //Command to switch on cursor
}

/* Makes cursor invisible */
void CursorOFF(void)
{
    WriteCommandLCD(0x0c);          //Command to switch off cursor
}

/* Displays a message on LCD */
void DisplayLCD(char LineNumber,char *Message)
{
    if(LineNumber ==1)
    {   //First Line
        WriteCommandLCD(0x80);      //Select the first line
    }
    else
    {   //Second line
        WriteCommandLCD(0xc0);      //Select the second line
    }
    while (*Message !=0)
    {
        WriteDataLCD(*Message++);
    }
}
