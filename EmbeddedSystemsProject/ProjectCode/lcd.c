#include "lcd.h"
#include "clock.h"
#include "keypad.h"
#include <stdio.h>

void lcdInit(void) {
    // initialise PA2 and PA3 - took out lock statement
	SYSCTL_RCGC2_R |= 0x08;     	  // 1) activate bit 1
    SysTick_Wait(100);                // delay  
    GPIO_PORTA_CR_R = 0x30;           // allow changes to PA2, PA3       
    GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog function
    GPIO_PORTA_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
    GPIO_PORTA_DIR_R = 0x06;          // 5) PA2, PA3 output  
    GPIO_PORTA_AFSEL_R = 0x00;        // 6) no alternate function      
    GPIO_PORTA_DEN_R = 0x06;          // 7) enable digital pins PA2, PA3
        
	// initialise PB4:PB7 - took out lock statement
	SYSCTL_RCGC2_R |= 0x10;     	  // 1) activate bit 2
    SysTick_Wait(100);                // delay  
    GPIO_PORTB_CR_R = 0x3C0;          // allow changes to PB4:PB7      
    GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
    GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
    GPIO_PORTB_DIR_R = 0xF0;          // 5) PB4, PB5, PB6, PB7 output   
    GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function      
    GPIO_PORTB_DEN_R = 0xF0;          // 7) enable digital pins PD4-PD0

    initDisplayPort();
}

void initDisplayPort() {
    GPIO_PA2_EN = 0x0;
    GPIO_DB = 0x0;

    SysTick_Wait(WAIT_15ms);

    GPIO_DB = 0x0C;
    SysTick_Wait(WAIT_4p1ms);

    GPIO_DB = 0x0C;
    SysTick_Wait(WAIT_100us);

    GPIO_DB = 0x0C;

    lcdWriteCommand(0x28);            // 4-bit data at a time, 2 line, 5x8 font (0010 1000)
    lcdWriteCommand(0x08);            // Display off control                    (0000 1000)
    lcdWriteCommand(0x0F);            // Dislpay on control                     (0000 1111)
    lcdWriteCommand(0x01);            // Clear display                          (0000 0001)
    lcdWriteCommand(0x06);            // entry mode set                         (0000 0111)

}

void lcdWriteCommand(unsigned char command) {
    // Send the high nibble first
    sendDisplayNibble((command >> 4) & 0x0F, 0);

    // Send the low nibble
    sendDisplayNibble(command & 0x0F, 0);

    // Additional delay if needed
    SysTick_Wait(WAIT_4p1ms); // Adjust the delay as necessary
}

void sendDisplayNibble(unsigned char nibble, int isData) {
    // 1. Set up RS pin : 0 for instructions, 1 for data (0 for init. instructions)
    GPIO_PA3_RS = isData;

    // 2. Send nibble to the bits of the port
    GPIO_DB = (GPIO_DB & 0xF0) | (nibble & 0x0F);

    // 3. Pulse the EN line for 450ns.
    lcdENPulse();
}

void sendDisplayByte(unsigned char byte, int isData) {
    // sends an 8 bit quantity to the LCD. Must be sent 4 at a time using sendDisplayNibble() twice.
    // send Bits 4-7 first, then bits 0-3.
    // see section 5.5 on pg. 9 of the datasheet for an example.

    // Send the high nibble
    sendDisplayNibble((byte >> 4) & 0x0F, 1); // Assuming RS is set for data

    // Send the low nibble
    sendDisplayNibble(byte & 0x0F, 1); // Assuming RS is set for data

    // Additional delay if needed
    SysTick_Wait(WAIT_4p1ms); // Adjust the delay as necessary
}

void lcdClearScreen(void) {
    lcdWriteCommand(0x01);          // clear screen
    lcdWriteCommand(0x02);          // return cursor home
}

void lcdGoto(unsigned char row, unsigned char column) {
    if (row == 0) {
        lcdWriteCommand(0x80 + column);
    } else {
        lcdWriteCommand(0xC0 + column);
    }
}

void lcdWriteRamString(char *string) {
    while(*string) {
		sendDisplayByte(*string, 1);
		string++;
	}
}

void lcdENPulse(void) {
    GPIO_PA2_EN = 0x04;     // pulse EN to high
	SysTick_Wait(WAIT_450ns); // pulse width of 450ns
	GPIO_PA2_EN = 0x00;     // pulse EN to low
	SysTick_Wait(WAIT_450ns);
}