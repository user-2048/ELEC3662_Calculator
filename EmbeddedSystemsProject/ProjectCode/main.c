/**********************************************************************************
// 0. Documentation Section 
// main.c
// Runs TM4C123
// Lab2_HelloLaunchPad, Input from PF4, output to PF3,PF2,PF1 (LED)
// Authors: Karolina Mungai Ndungu (el21kamn)
// Date started: 16/11/23
**********************************************************************************/

// LaunchPad built-in hardware
// SW1 left switch is negative logic PF4 on the Launchpad
// SW2 right switch is negative logic PF0 on the Launchpad
// red LED connected to PF1 on the Launchpad
// blue LED connected to PF2 on the Launchpad
// green LED connected to PF3 on the Launchpad

// 1. Pre-processor Directives Section
// Constant declarations to access port registers using 
// symbolic names instead of addresses
#include "TExaS.h"
#include "defines.h" // definitions of all ports in here!

// 2. Declarations Section
//   Global Variables
//unsigned long In;  // input from PF4
//unsigned long Out; // outputs to PF3,PF2,PF1 (multicolor LED)

//   Function Prototypes
void keypadInit(void); // PORTD and PORTE setup and number of rows/columns of the matrix.
unsigned char readKeypad(); // This function returns the key pressed in the keypad matrix.
char decodeKeyPress(unsigned char k); // This function returns the value of the pressed keypad button. could combine with readKeypad.

void Delay(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){    

}

// PORTD and PORTE setup and number of rows/columns of the matrix.
// testing git comment?? - DELETE
void keypadInit(){ volatile unsigned long delay; 
	// init PORTD [0,3]
	SYSCTL_RCGC2_R |= 0x08;     			// 1) activate bit 3
  delay = SYSCTL_RCGC2_R;           // delay  
	GPIO_PORTD_LOCK_R = 0x4C4F434B;   // 2) unlock PortD PD0  
  GPIO_PORTD_CR_R = 0x3C;           // allow changes to PD3-0       
  GPIO_PORTD_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTD_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTD_DIR_R = 0x0F;          // 5) PD0, PD1, PD2, PD3 output   
  GPIO_PORTD_AFSEL_R = 0x00;        // 6) no alternate function      
  GPIO_PORTD_DEN_R = 0x0F;          // 7) enable digital pins PD4-PD0

		// init PORTE [0,3]
	SYSCTL_RCGC2_R |= 0x10;     			// 1) activate bit 4
  delay = SYSCTL_RCGC2_R;           // delay  
	GPIO_PORTE_LOCK_R = 0x4C4F434B;   // 2) unlock PortE PE0  
  GPIO_PORTE_CR_R = 0x0f;           // allow changes to PE3-0       
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x00;          // 5) PE0, PE1, PE2, PE3 inputs 
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function      
  GPIO_PORTE_DEN_R = 0x0F;          // 7) enable digital pins PE3-PE0

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
