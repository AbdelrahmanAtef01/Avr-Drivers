#include "I2C_Configuration.h"
#include "I2C_Interface.h"
#include "I2C_Address.h"
#include "I2C_Private.h"

void I2C_InitMaster(I2C_Clock_t clock, I2C_Prescaler_t prescaler) {
	// Set clock frequency and prescaler
	TWBR = clock;
	TWSR = prescaler & 0x03;

	// Enable I2C (TWI)
	TWCR = (1 << TWEN);
}

void I2C_MasterSendStartCondition(void) {
	// Send START condition
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// Wait for TWINT flag to be set, indicating start condition transmitted
	while (!(TWCR & (1 << TWINT)));
}

void I2C_MasterSendStopCondition(void) {
	// Send STOP condition
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

	// No need to wait for stop condition to complete
}

void I2C_MasterSendRepeatedStartCondition(void) {
	// Send repeated START condition
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));
}

void I2C_MasterSendSlaveAddressWithWrite(I2C_SlaveAddress_t slaveAddress) {
	// Load slave address with write operation (LSB = 0)
	TWDR = (slaveAddress << 1);
	
	// Clear TWINT to start transmission
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));
}

void I2C_MasterSendSlaveAddressWithRead(I2C_SlaveAddress_t slaveAddress) {
	// Load slave address with read operation (LSB = 1)
	TWDR = (slaveAddress << 1) | 1;

	// Clear TWINT to start transmission
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));
}

void I2C_MasterTransmitDataByte(uint8_t data) {
	// Load data into TWDR
	TWDR = data;

	// Clear TWINT to start transmission
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));
}

uint8_t I2C_MasterReceiveDataByteWithACK(void) {
	// Clear TWINT and enable acknowledgment
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));

	// Return received data
	return TWDR;
}

uint8_t I2C_MasterReceiveDataByteWithNoACK(void) {
	// Clear TWINT and disable acknowledgment
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));

	// Return received data
	return TWDR;
}

// Slave functions
void I2C_InitSlave(I2C_SlaveAddress_t slaveAddress) {
	// Set slave address
	TWAR = slaveAddress << 1;

	// Enable I2C and acknowledgment
	TWCR = (1 << TWEN) | (1 << TWEA);
}

void I2C_SlaveTransmitDataByte(uint8_t data) {
	// Load data into TWDR
	TWDR = data;

	// Clear TWINT to start transmission
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));
}

uint8_t I2C_SlaveReceiveDataByte(void) {
	// Clear TWINT to start reception
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	// Wait for TWINT flag to be set
	while (!(TWCR & (1 << TWINT)));

	// Return received data
	return TWDR;
}

