#ifndef _TMR2_INTERFACE_H
#define _TMR2_INTERFACE_H

#include "TMR2_Config.h"

// Initialize the timer with configuration
void TMR2_Init(void);

// Start the timer for a given time in milliseconds
void TMR2_Start(uint16_t milliseconds);

// Stop the timer
void TMR2_Stop(void);

// Set a callback function to be called after the timer completes
void TMR2_SetCallback(void (*callbackFunc)(void));

#endif /* _TMR2_INTERFACE_H */

