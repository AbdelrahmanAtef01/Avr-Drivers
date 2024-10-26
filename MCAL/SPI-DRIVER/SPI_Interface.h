#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_Configuration.h"


// SPI function prototypes
void SPI_InitMaster(SPI_Mode_t mode, SPI_DataOrder_t dataOrder, SPI_ClockRate_t clockRate);
void SPI_InitSlave(SPI_Mode_t mode, SPI_DataOrder_t dataOrder);
void SPI_Transmit(uint8_t data);
uint8_t SPI_Receive(void);
uint8_t SPI_Transceive(uint8_t data);

#endif /* SPI_INTERFACE_H_ */
