#ifndef _WDT_CONFIG_H
#define _WDT_CONFIG_H

#include "../../CONFIG/CPU_Configuration.h"

// Define Watchdog Timer timeout options (based on AVR's predefined timeouts)
#define WDT_TIMEOUT_16MS     0x00  // 16 milliseconds
#define WDT_TIMEOUT_32MS     0x01  // 32 milliseconds
#define WDT_TIMEOUT_64MS     0x02  // 64 milliseconds
#define WDT_TIMEOUT_125MS    0x03  // 125 milliseconds
#define WDT_TIMEOUT_250MS    0x04  // 250 milliseconds
#define WDT_TIMEOUT_500MS    0x05  // 500 milliseconds
#define WDT_TIMEOUT_1S       0x06  // 1 second
#define WDT_TIMEOUT_2S       0x07  // 2 seconds
#define WDT_TIMEOUT_4S       0x08  // 4 seconds (if supported)
#define WDT_TIMEOUT_8S       0x09  // 8 seconds (if supported)

// Choose the default timeout period for the WDT (can be overridden at runtime)
#define WDT_DEFAULT_TIMEOUT  WDT_TIMEOUT_2S

#endif /* _WDT_CONFIG_H */
