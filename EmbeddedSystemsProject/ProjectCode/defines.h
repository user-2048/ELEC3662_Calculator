#ifndef DEFINES_H_  
#define DEFINES_H_

// definitions
// define port A pins 2 & 3 : Port A Base Address = 0x4000.4000
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x40004030)) // pin-specific referencing as we are only using pins 2 and 3
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400)) // Pin Direction Register
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420)) // Special Function Enable
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C)) // Digital Pin Enable
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528)) // Analogue Mode Select
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C)) // Special Function Specifier
	
// port b, pins [4,7]
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053C0)) // Reference only [4,7]
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))


// port d, pins [0,3]
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x4000503C)) // Reference only [0,3]
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000552C))

// port e, pins [0,3]
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x4002403C)) // Reference only [0,3]
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024514)) // Pull down resistor, PE only
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))

	
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108)) // GPIO Clock Register

#endif // DEFINES_H_