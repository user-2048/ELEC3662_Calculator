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
#include <stdio.h>
#include <math.h>

// 2. Declarations Section
//   Global Variables

//   Function Prototypes
void Delay(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){    

}

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
