/**********************************************************************************
*       0. Documentation Section                                                  *
*       main.c                                                                    *
*       Runs TM4C123                                                              *
*       Authors: Karolina Mungai Ndungu (el21kamn)                                *
*       Date started: 16/11/23                                                    *
**********************************************************************************/

// 1. Pre-processor Directives Section
#include "TExaS.h"
#include "defines.h" // definitions of all ports in here!
#include "clock.h"
#include "lcd.h"
#include "keypad.h"

#include <stdio.h>
#include <math.h>

// 2. Declarations Section

//   Global Variables

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){    
  // // Call initialising functions
  SysTick_Init();
  // PLL_Init();
  // keypadInit();
  // lcdInit();

  // while(1) {
  //   printf("Begin calculator functions.");
  //   SysTick_Wait(5000); // wait 5 seconds
  //   printf("End while loop");
  //   break;
  // }

  // SysTick_Wait(7000);
  // printf("Okay end function");

  return 1; 
}