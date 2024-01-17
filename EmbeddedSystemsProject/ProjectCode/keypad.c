#include "keypad.h"
#include "clock.h"
#include "lcd.h"
#include <stdio.h>

// PORTD and PORTE setup and number.
void keypadInit(){ volatile unsigned long delay; 
	// init PORTD [0,3] - These will be the keypad COLUMNS
	SYSCTL_RCGC2_R |= 0x20;     			// 1) activate bit 3
  delay = SYSCTL_RCGC2_R;           // delay  
	GPIO_PORTD_LOCK_R = 0x4C4F434B;   // 2) unlock PortD PD0  
  GPIO_PORTD_CR_R = 0x3C;           // allow changes to PD3-PD0       
  GPIO_PORTD_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTD_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTD_DIR_R = 0x00;          // 5) PD0, PD1, PD2, PD3 input   
  GPIO_PORTD_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTD_PDR_R = 0x3C;          // enable pull-down resistor on bits PD3-PD0
  GPIO_PORTD_DEN_R = 0x0F;          // 7) enable digital pins PD3-PD0

	// init PORTE [0,3] - These will be the keypad ROWS
	SYSCTL_RCGC2_R |= 0x40;     			// 1) activate bit 4
  delay = SYSCTL_RCGC2_R;           // delay
	GPIO_PORTE_LOCK_R = 0x4C4F434B;   // 2) unlock PortE PE0  
  GPIO_PORTE_CR_R = 0x0F;           // allow changes to PE3-0       
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x00;          // 5) PE0, PE1, PE2, PE3 inputs 
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function      
  GPIO_PORTE_DEN_R = 0x0F;          // 7) enable digital pins PE3-PE0

}

// This function returns the key pressed in the keypad matrix.
// decodeKeyPress() is implemented within this function so no need to make a separate function
unsigned char readKeypad() {
  // store keypad layout in a 2D character array:
  char keypad[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
  };

  for (int col = 0; col < 4; col++) {
    // set current column to HIGH
    GPIO_PORTD_DATA_R = 1 << col;

    // delay
    SysTick_Wait(WAIT_450ns);

    int rowState = GPIO_PORTD_DATA_R & 0x0F;

    for (int row = 0; row < 4; row++) {
      if ((rowState & (1 << row)) == 0) {
        // Key is pressed, get the corresponding character
        char button = keypad[row][col];
        // Reset the current column to LOW after reading
        GPIO_PORTD_DATA_R = 0;

        return button;
      }
    }
  }

  return '\0'; // no key was pressed
}

int decodeNumkey(char c) {
  // Check if the character is a digit
  if ('0' <= c && c <= '9') {
      // Convert the character to its integer value
      return c - '0';
  } else {
      // Handle other cases or return an error value
      return -1; // Example: Return -1 for non-digit characters
  }
}