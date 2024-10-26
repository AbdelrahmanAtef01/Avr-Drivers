#include "TMR2_Config.h"
#include "TMR2_Interface.h"
#include "TMR2_Address.h"

// Pointer to the user-defined callback function
static void (*TMR2_Callback)(void) = 0;

// Number of compare matches required to reach the desired time
static uint16_t TMR2_RequiredMatches = 0;

// Counter to track the number of compare matches
static uint16_t TMR2_CurrentMatches = 0;

// Function prototypes
static uint16_t TMR2_CalculateTicks(uint16_t milliseconds);

void TMR2_Init(void)
{
	// Enable global interrupts
	SREG |= (1 << 7);

	// Set mode based on configuration
	#if TMR2_MODE == TMR2_MODE_NORMAL
	TCCR2_REG &= ~(1 << TCCR2_WGM20);
	TCCR2_REG &= ~(1 << TCCR2_WGM21);  // Normal mode
	#elif TMR2_MODE == TMR2_MODE_CTC
	TCCR2_REG &= ~(1 << TCCR2_WGM20);
	TCCR2_REG |= (1 << TCCR2_WGM21);   // CTC mode
	#elif TMR2_MODE == TMR2_MODE_PWM
	TCCR2_REG |= (1 << TCCR2_WGM20);
	TCCR2_REG |= (1 << TCCR2_WGM21);   // Fast PWM mode
	#endif

	// Enable Timer interrupt based on the mode
	#if TMR2_MODE == TMR2_MODE_NORMAL
	TIMSK_REG |= (1 << TIMSK_TOIE2);   // Enable Overflow Interrupt
	#elif TMR2_MODE == TMR2_MODE_CTC
	TIMSK_REG |= (1 << TIMSK_OCIE2);   // Enable Compare Match Interrupt
	#endif
}

void TMR2_Start(uint16_t milliseconds)
{
	uint16_t ticks = TMR2_CalculateTicks(milliseconds);

	// Set compare value for CTC mode
	if (TMR2_MODE == TMR2_MODE_CTC)
	{
		OCR2_REG = ticks;
	}

	// Reset the match counter
	TMR2_CurrentMatches = 0;

	// Start the timer with the configured prescaler
	switch (TMR2_PRESCALER)
	{
		case TMR2_PRESCALER_NO:
		TCCR2_REG |= (1 << TCCR2_CS20);
		break;
		case TMR2_PRESCALER_8:
		TCCR2_REG |= (1 << TCCR2_CS21);
		break;
		case TMR2_PRESCALER_32:
		TCCR2_REG |= (1 << TCCR2_CS20) | (1 << TCCR2_CS21);
		break;
		case TMR2_PRESCALER_64:
		TCCR2_REG |= (1 << TCCR2_CS22);
		break;
		case TMR2_PRESCALER_128:
		TCCR2_REG |= (1 << TCCR2_CS20) | (1 << TCCR2_CS22);
		break;
		case TMR2_PRESCALER_256:
		TCCR2_REG |= (1 << TCCR2_CS21) | (1 << TCCR2_CS22);
		break;
		case TMR2_PRESCALER_1024:
		TCCR2_REG |= (1 << TCCR2_CS20) | (1 << TCCR2_CS21) | (1 << TCCR2_CS22);
		break;
	}
}

void TMR2_Stop(void)
{
	// Stop the timer by clearing the clock source bits
	TCCR2_REG &= ~((1 << TCCR2_CS20) | (1 << TCCR2_CS21) | (1 << TCCR2_CS22));
}

void TMR2_SetCallback(void (*callbackFunc)(void))
{
	TMR2_Callback = callbackFunc;
}

// Interrupt Service Routine for Timer2 Compare Match
ISR(TIMER2_COMP_vect)
{
	TMR2_CurrentMatches++;
	
	// Check if we've reached the required number of matches
	if (TMR2_CurrentMatches >= TMR2_RequiredMatches)
	{
		if (TMR2_Callback != 0)
		{
			TMR2_Callback();
		}
		TMR2_CurrentMatches = 0;  // Reset matches for the next cycle
	}
}

// Function to calculate ticks based on the desired time in milliseconds and the configured prescaler
static uint16_t TMR2_CalculateTicks(uint16_t milliseconds)
{
	uint32_t prescaler_value = 1;
	switch (TMR2_PRESCALER)
	{
		case TMR2_PRESCALER_NO:
		prescaler_value = 1;
		break;
		case TMR2_PRESCALER_8:
		prescaler_value = 8;
		break;
		case TMR2_PRESCALER_32:
		prescaler_value = 32;
		break;
		case TMR2_PRESCALER_64:
		prescaler_value = 64;
		break;
		case TMR2_PRESCALER_128:
		prescaler_value = 128;
		break;
		case TMR2_PRESCALER_256:
		prescaler_value = 256;
		break;
		case TMR2_PRESCALER_1024:
		prescaler_value = 1024;
		break;
	}

	// Calculate ticks based on prescaler and the desired time in milliseconds
	uint32_t ticks = ((F_CPU / (prescaler_value * 1000)) * milliseconds);

	// If the number of ticks exceeds 255 (the max value for an 8-bit timer), calculate how many compare matches are required
	if (ticks > 255)
	{
		TMR2_RequiredMatches = ticks / 255;
	}
	else
	{
		TMR2_RequiredMatches = 1;  // Only one match is needed
	}

	return (uint16_t)ticks;
}

