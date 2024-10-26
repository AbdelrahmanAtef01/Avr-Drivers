#ifndef I2C_CONFIGURATION_H_
#define I2C_CONFIGURATION_H_

#include "../CONFIG/CPU_Configuration.h"

// Define I2C clock frequency
typedef enum {
	I2C_CLOCK_100KHZ = 72,  // For 100 kHz I2C clock with 16 MHz CPU clock
	I2C_CLOCK_400KHZ = 12   // For 400 kHz I2C clock with 16 MHz CPU clock
} I2C_Clock_t;

// Define Slave Address type (7-bit address)
typedef uint8_t I2C_SlaveAddress_t;

// Define Prescaler Options
typedef enum {
	I2C_PRESCALER_1 = 0b00,
	I2C_PRESCALER_4 = 0b01,
	I2C_PRESCALER_16 = 0b10,
	I2C_PRESCALER_64 = 0b11
} I2C_Prescaler_t;

// Default Configuration
#define I2C_DEFAULT_CLOCK        I2C_CLOCK_100KHZ
#define I2C_DEFAULT_PRESCALER    I2C_PRESCALER_64
#define I2C_DEFAULT_SLAVE_ADDR   0x01  // Default slave address

#endif /* I2C_CONFIGURATION_H_ */

