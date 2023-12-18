#include "defines.h"
void keypadInit(void); // PORTD and PORTE setup and number of rows/columns of the matrix.

unsigned char readKeypad(); // This function returns the key pressed in the keypad matrix.

char decodeKeyPress(unsigned char k); // This function returns the value of the pressed keypad button. could combine with readKeypad.