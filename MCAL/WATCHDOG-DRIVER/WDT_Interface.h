#ifndef _WDT_INTERFACE_H
#define _WDT_INTERFACE_H

#include "WDT_Config.h"

// Initialize the Watchdog Timer with a specified timeout (or default from WDT_Config.h)
void WDT_Init(uint8_t timeout);

// Reset ("kick") the Watchdog Timer to prevent a system reset
void WDT_Reset(void);

// Disable the Watchdog Timer
void WDT_Disable(void);

#endif /* _WDT_INTERFACE_H */
