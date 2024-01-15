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
	
}

void sendDisplayNibble(volatile unsigned long delay) {
    // 1. Set up RS pin : 0 for instructions, 1 for data (0 for init. instructions)


    // 2. Send nibble to the bits of the port


    // 3. Pulse the EN line for 450ns.
	
}

void sendDisplayByte() {
    // sends an 8 bit quantity to the LCD. Must be sent 4 at a time using sendDisplayNibble() twice.
    // send Bits 4-7 first, then bits 0-3.
    // see section 5.5 on pg. 9 of the datasheet for an example.
    
}

void initDisplayPort() {


}