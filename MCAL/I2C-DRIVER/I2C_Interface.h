#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "I2C_Configuration.h"

// Master Functions
void I2C_InitMaster(I2C_Clock_t clock, I2C_Prescaler_t prescaler);
void I2C_MasterSendStartCondition(void);
void I2C_MasterSendStopCondition(void);
void I2C_MasterSendRepeatedStartCondition(void);
void I2C_MasterSendSlaveAddressWithWrite(I2C_SlaveAddress_t slaveAddress);
void I2C_MasterSendSlaveAddressWithRead(I2C_SlaveAddress_t slaveAddress);
void I2C_MasterTransmitDataByte(uint8_t data);
uint8_t I2C_MasterReceiveDataByteWithACK(void);
uint8_t I2C_MasterReceiveDataByteWithNoACK(void);

// Slave Functions
void I2C_InitSlave(I2C_SlaveAddress_t slaveAddress);
void I2C_SlaveTransmitDataByte(uint8_t data);
uint8_t I2C_SlaveReceiveDataByte(void);

#endif /* I2C_INTERFACE_H_ */
