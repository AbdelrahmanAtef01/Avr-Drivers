#ifndef _WDT_ADDRESS_H
#define _WDT_ADDRESS_H

// Watchdog Timer Control Register (WDTCR) for ATmega32
#define WDTCR   (*(volatile uint8_t *)0x41)  // WDTCR register address for ATmega32

// Bit positions in the WDTCR register
#define WDE      3   // Watchdog Enable
#define WDTOE    4   // Watchdog Turn-off Enable
#define WDP0     0   // Watchdog Prescaler bit 0
#define WDP1     1   // Watchdog Prescaler bit 1
#define WDP2     2   // Watchdog Prescaler bit 2

#endif /* _WDT_ADDRESS_H */

