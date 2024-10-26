#ifndef USART_CONFIGURATION_H_
#define USART_CONFIGURATION_H_

#include "../CONFIG/CPU_Configuration.h"

// Baud rate options (assuming a 16 MHz clock)
typedef enum {
	USART_BAUD_9600   = 103,
	USART_BAUD_115200 = 8
} USART_BaudRate_t;

// Character Size options
typedef enum {
	USART_CHAR_SIZE_5 = 0b00,
	USART_CHAR_SIZE_6 = 0b01,
	USART_CHAR_SIZE_7 = 0b10,
	USART_CHAR_SIZE_8 = 0b11
} USART_CharSize_t;

// Parity Mode options
typedef enum {
	USART_PARITY_NONE = 0b00,
	USART_PARITY_EVEN = 0b10,
	USART_PARITY_ODD  = 0b11
} USART_Parity_t;

// Stop Bit options
typedef enum {
	USART_STOP_1 = 0,
	USART_STOP_2 = 1
} USART_StopBits_t;

// Default configuration values (if needed for initialization)
#define USART_DEFAULT_BAUD        USART_BAUD_9600
#define USART_DEFAULT_CHAR_SIZE   USART_CHAR_SIZE_8
#define USART_DEFAULT_PARITY      USART_PARITY_NONE
#define USART_DEFAULT_STOP_BITS   USART_STOP_1

#endif /* USART_CONFIGURATION_H_ */

