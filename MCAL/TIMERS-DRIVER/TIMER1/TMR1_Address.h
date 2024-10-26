#ifndef _TMR1_ADDRESS_H
#define _TMR1_ADDRESS_H

// Timer/Counter1 Control Register A (TCCR1A) and B (TCCR1B)
#define TCCR1A_REG    (*(volatile uint8_t *)0x4F)
#define TCCR1B_REG    (*(volatile uint8_t *)0x4E)
#define TCNT1_REG     (*(volatile uint16_t *)0x4C)  // Timer/Counter Register (16-bit)
#define OCR1A_REG     (*(volatile uint16_t *)0x4A)  // Output Compare Register A
#define OCR1B_REG     (*(volatile uint16_t *)0x48)  // Output Compare Register B
#define ICR1_REG      (*(volatile uint16_t *)0x46)  // Input Capture Register (used in PWM mode)
#define TIMSK_REG     (*(volatile uint8_t *)0x59)   // Timer Interrupt Mask Register
#define TIFR_REG      (*(volatile uint8_t *)0x58)   // Timer Interrupt Flag Register

// TCCR1A bit positions
#define COM1A1    7
#define COM1A0    6
#define COM1B1    5
#define COM1B0    4
#define WGM11     1
#define WGM10     0

// TCCR1B bit positions
#define ICNC1     7
#define ICES1     6
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0

// TIMSK bit positions
#define TOIE1     2
#define OCIE1A    4
#define OCIE1B    3

#endif /* _TMR1_ADDRESS_H */
