#ifndef DEFINES_H_  
#define DEFINES_H_

// Constant declarations to access port registers using 
// symbolic names instead of addresses

// definitions
// define port A pins 2 & 3 : Port A Base Address = 0x4000.4000
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC)) // pin-specific referencing as we are only using pins 2 and 3
#define GPIO_PA2 				(*((volatile unsigned long *)0x40004010))
#define GPIO_PA3				(*((volatile unsigned long *)0x40004020))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400)) // Pin Direction Register
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420)) // Special Function Enable
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C)) // Digital Pin Enable
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528)) // Analogue Mode Select
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C)) // Special Function Specifier
	
// port b, pins [4,7] : Port B Base Address = 0x4000.5000
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053C0)) // Reference only [4,7]
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))

// port d, pins [0,3] : Port D Base Address = 0x4000.7000
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x4000703C)) // Reference only [0,3]
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_PDR_R        (*((volatile unsigned long *)0x40007514)) // Pull down resistor, PD (rows) only
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))

// port e, pins [0,3] : Port E Base Address = 0x4002.4000
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x4002403C)) // Reference only [0,3]
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))

// // GPIO Clock Register - May be able to delete!!
// #define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108)) 
//PLL related Defines
#define SYSCTL_RIS_R          (*((volatile unsigned long *)0x400FE050))	
#define SYSCTL_RCC_R          (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC2_R         (*((volatile unsigned long *)0x400FE070))	

//SysTick related Defines	
#define NVIC_ST_CTRL_R        (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R      (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R     (*((volatile unsigned long *)0xE000E018))

#endif // DEFINES_H_