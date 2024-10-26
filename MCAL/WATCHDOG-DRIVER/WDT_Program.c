#include "WDT_Config.h"
#include "WDT_Interface.h"
#include "WDT_Address.h"

// Function to enable the Watchdog Timer with a specified timeout
void WDT_Init(uint8_t timeout)
{
	// Disable global interrupts while configuring WDT
	cli();

	// Start the timed sequence to enable or modify the Watchdog Timer.
	WDTCR |= (1 << WDTOE) | (1 << WDE);

	// Set the watchdog timeout and enable the watchdog timer
	WDTCR = (1 << WDE) | (timeout & 0x07);  // Set WDE and prescaler bits (timeout)

	// Enable global interrupts again
	sei();
}

// Function to reset the Watchdog Timer to prevent a system reset
void WDT_Reset(void)
{
	// Assembly instruction to reset ("kick") the Watchdog Timer
	__asm__ __volatile__ ("wdr");
}

// Function to disable the Watchdog Timer
void WDT_Disable(void)
{
	// Disable global interrupts while disabling WDT
	cli();

	// Start the timed sequence to disable the Watchdog Timer.
	WDTCR |= (1 << WDTOE) | (1 << WDE);

	// Disable the Watchdog Timer by clearing the WDE bit.
	WDTCR = 0x00;

	// Enable global interrupts again
	sei();
}
