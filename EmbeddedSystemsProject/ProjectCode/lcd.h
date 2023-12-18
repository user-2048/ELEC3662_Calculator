#include "defines.h"

void lcdInit(void);

void lcdENPulse(); // to latch commands

void sendDisplayNibble(volatile unsigned long delay);