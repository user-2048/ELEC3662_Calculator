/**********************************************************************************
*       0. Documentation Section                                                  *
*       main.c                                                                    *
*       Runs TM4C123                                                              *
*       Authors: Karolina Mungai Ndungu (el21kamn)                                *
*       Date started: 16/11/23                                                    *
**********************************************************************************/

// 1. Pre-processor Directives Section
// Constant declarations to access port registers using 
// symbolic names instead of addresses
#include "TExaS.h"
#include "defines.h" // definitions of all ports in here!

// 2. Declarations Section
//   Global Variables

//   Function Prototypes
void keypadInit(void); // PORTD and PORTE setup and number of rows/columns of the matrix.
unsigned char readKeypad(); // This function returns the key pressed in the keypad matrix.
char decodeKeyPress(unsigned char k); // This function returns the value of the pressed keypad button. could combine with readKeypad.
void lcdinit(volatile unsigned long delay);
void lcdENPulse(); // to latch commands
void sendDisplayNibble(volatile unsigned long delay);

void Delay(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){    

}

// PORTD and PORTE setup and number.
void keypadInit(){ volatile unsigned long delay; 
	// init PORTD [0,3]
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

	// init PORTE [0,3]
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
unsigned char readKeypad() {

}

// This function returns the value of the pressed keypad button. could combine with readKeypad.
char decodeKeyPress(unsigned char k) {
	
}

void lcdinit(volatile unsigned long delay) {
	// initialise PA2 and PA3 - took out lock statement
	SYSCTL_RCGC2_R |= 0x08;     			// 1) activate bit 1
  delay = SYSCTL_RCGC2_R;           // delay  
  GPIO_PORTA_CR_R = 0x30;           // allow changes to PA2, PA3       
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTA_DIR_R = 0x06;          // 5) PA2, PA3 output  
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) no alternate function      
  GPIO_PORTA_DEN_R = 0x06;          // 7) enable digital pins PA2, PA3
	
	// initialise PB4:PB7 - took out lock statement
	SYSCTL_RCGC2_R |= 0x10;     			// 1) activate bit 2
  delay = SYSCTL_RCGC2_R;           // delay  
  GPIO_PORTB_CR_R = 0x3C0;          // allow changes to PB4:PB7      
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R = 0xF0;          // 5) PB4, PB5, PB6, PB7 output   
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function      
  GPIO_PORTB_DEN_R = 0xF0;          // 7) enable digital pins PD4-PD0
	
}

void sendDisplayNibble(volatile unsigned long delay) {
	// 1. Set up RS pin : 0 for instructions, 1 for data
	
	
	// 2. Send nibble to the bits of the port
	
	
	// 3. Pulse the EN line for 450ns.
	
}



// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06

// Subroutine to wait 0.1 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){unsigned long volatile time;
  time = 727240*200/91;  // 0.1sec
  while(time){
                time--;
  }
}
