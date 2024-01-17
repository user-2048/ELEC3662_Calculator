#include "defines.h"

void lcdInit(void);

void initDisplayPort();

void lcdWriteCommand(unsigned char command);

void sendDisplayNibble(unsigned char nibble, int isData);

void sendDisplayByte(unsigned char byte, int isData);

void lcdClearScreen(void);

void lcdGoto(unsigned char row, unsigned char column);

void lcdWriteRamString(char *string);

void lcdENPulse(void);