#ifndef _TMR2_ADDRESS_H
#define _TMR2_ADDRESS_H

#include <stdint.h>

// Memory addresses for Timer2 registers
#define TCCR2_REG     (*((volatile uint8_t *)0x45))  // Timer/Counter2 Control Register
#define TCNT2_REG     (*((volatile uint8_t *)0x44))  // Timer/Counter2 Register
#define OCR2_REG      (*((volatile uint8_t *)0x43))  // Output Compare Register 2
#define TIMSK_REG     (*((volatile uint8_t *)0x59))  // Timer Interrupt Mask Register
#define TIFR_REG      (*((volatile uint8_t *)0x58))  // Timer Interrupt Flag Register

// Bit positions
#define TCCR2_CS20    0
#define TCCR2_CS21    1
#define TCCR2_CS22    2
#define TCCR2_WGM21   3
#define TCCR2_COM20   4
#define TCCR2_COM21   5
#define TCCR2_WGM20   6
#define TCCR2_FOC2    7

#define TIMSK_TOIE2   6
#define TIMSK_OCIE2   7

#endif /* _TMR2_ADDRESS_H */
