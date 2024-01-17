// function declarations
#include "defines.h"

// define time values for Systick_Wait
#define WAIT_30s 2400000000
#define WAIT_3s 240000000
#define WAIT_15ms 1200000
#define WAIT_4p1ms 328000
#define WAIT_100us 8000
#define WAIT_450ns 36

void SysTick_Init(void);

void PLL_Init(void);

void SysTick_Wait(unsigned long delay);