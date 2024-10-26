#ifndef _TMR1_INTERFACE_H
#define _TMR1_INTERFACE_H

#include "TMR1_config.h"

// Initialize Timer1 with configuration options
void TMR1_Init(void);

// Start Timer1 with a given top value (in milliseconds)
void TMR1_Start(uint16_t milliseconds);

// Stop Timer1
void TMR1_Stop(void);

// Set callback for Timer1 Compare Match A interrupt
void TMR1_SetCallbackA(void (*callbackFunc)(void));

// Set callback for Timer1 Compare Match B interrupt
void TMR1_SetCallbackB(void (*callbackFunc)(void));

// Set callback for Timer1 Overflow interrupt in Normal mode
void TMR1_SetOverflowCallback(void (*callbackFunc)(void));

// PWM Functions
// Set PWM duty cycle for Channel A (0-100% range)
void TMR1_PWM_SetDutyCycleA(uint8_t duty_cycle);

// Set PWM duty cycle for Channel B (0-100% range)
void TMR1_PWM_SetDutyCycleB(uint8_t duty_cycle);

// Set PWM frequency for Fast or Phase-correct PWM modes
void TMR1_PWM_SetFrequency(uint32_t frequency);

#endif /* _TMR1_INTERFACE_H */


