#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include "../CONFIG/CPU_Configuration.h"

// SPI Modes
typedef enum {
	SPI_MODE_0 = 0b00,  // CPOL = 0, CPHA = 0
	SPI_MODE_1 = 0b01,  // CPOL = 0, CPHA = 1
	SPI_MODE_2 = 0b10,  // CPOL = 1, CPHA = 0
	SPI_MODE_3 = 0b11   // CPOL = 1, CPHA = 1
} SPI_Mode_t;

// SPI Data Order
typedef enum {
	SPI_MSB_FIRST = 0,
	SPI_LSB_FIRST = 1
} SPI_DataOrder_t;

// SPI Clock Rate (fosc / divider)
typedef enum {
	SPI_CLOCK_DIV4   = 0b00,
	SPI_CLOCK_DIV16  = 0b01,
	SPI_CLOCK_DIV64  = 0b10,
	SPI_CLOCK_DIV128 = 0b11
} SPI_ClockRate_t;

// Default SPI configuration
#define SPI_DEFAULT_MODE         SPI_MODE_0
#define SPI_DEFAULT_DATA_ORDER   SPI_MSB_FIRST
#define SPI_DEFAULT_CLOCK_RATE   SPI_CLOCK_DIV128

#endif /* SPI_CONFIGURATION_H_ */
