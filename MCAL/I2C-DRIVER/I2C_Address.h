#ifndef I2C_ADDRESS_H_
#define I2C_ADDRESS_H_

#include <stdint.h>

// I2C (TWI) Control Register
#define TWCR    (*(volatile uint8_t*)0x56)

// I2C (TWI) Status Register
#define TWSR    (*(volatile uint8_t*)0x21)

// I2C (TWI) Data Register
#define TWDR    (*(volatile uint8_t*)0x23)

// I2C (TWI) Bit Rate Register
#define TWBR    (*(volatile uint8_t*)0x20)

// I2C (TWI) Address Register
#define TWAR    (*(volatile uint8_t*)0x22)

// Bit positions in TWCR (Control Register)
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0

// Bit positions in TWSR (Status Register)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#endif /* I2C_ADDRESS_H_ */
