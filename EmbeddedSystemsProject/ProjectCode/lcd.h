#include "defines.h"

void lcdInit(volatile unsigned long delay);

void lcdENPulse(); // to latch commands

void sendDisplayNibble(volatile unsigned long delay);