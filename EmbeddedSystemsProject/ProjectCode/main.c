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
// Global vaiables
char key;
double number1 = 0;
double number2 = 0;
double answer = 0;
char operator;

// calculator functions
void runCalculator(void);
void clearAll();
double calculate();

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){    
  // initialise ports:
  PLL_Init();
  keypadInit();
  lcdInit();
  lcdClearScreen();

  runCalculator();

  return 1; 
}

void runCalculator(void) {
	while (1) {
    key = readKeypad();

    while ('0' <= key && key <= '9') { // key is a number
    	// writeCharater(key, 1)
		int n = decodeNumkey(key);
		number1 = (number1*10)+n; // store first number
    	key = readKeypad(); // read next key
    }
	if (key == 'A' || key == 'B' || key == 'C' || key == 'D') { // operators A, B, C, D
		if (key == 'D') {
			key = readKeypad();
			// write corresponding character to display SHIFTED
			// store operator in op variable
			if (key == 'A') {	
			operator = 'x';
			} else if (key == 'B') { 
			operator = '/';
			} else if (key == 'C') { 
			operator = 'E';
			}
		} else {
			// write corresponding character to display
			// store operator in op variable
			if (key == 'A') {
			operator = '+';
			} else if (key == 'B') {
			operator = '-';
			} else if (key == 'C') {
			operator = '.';
			}
		}
    }
	key = readKeypad();
	while ('0' <= key && key <= '9') { // key is a number
    	// writeCharater(key, 1)
		int n = decodeNumkey(key);
		number2 = (number2*10)+n; // store first number
    	key = readKeypad(); // read next key
    }
	if (key == '*') {
		answer = calculate();
	}
	// for any key that isn't a number, do nothing
	;
  }
}

void clearAll() {
  lcdClearScreen();
  key = '\0';
  number1 = 0;
  number2 = 0;
  answer = 0;
  operator = '\0';
  // zero any other variables TODO
}

double calculate() {
	if (operator == '+') {
		answer = number1 + number2;
	} else if (operator == '-') {
    answer = number1 - number2;
  } else if (operator == 'x') {
    answer = number1*number2;
  } else if (operator == '/') {
    answer = number1/number2;
  }
	return 0.0;
}


