#include "SPI_Configuration.h"
#include "SPI_Interface.h"
#include "SPI_Address.h"
#include "SPI_Private.h"

void SPI_InitMaster(SPI_Mode_t mode, SPI_DataOrder_t dataOrder, SPI_ClockRate_t clockRate) {
	// Set MOSI, SCK as output, MISO as input
	DDRB |= (1 << PB5) | (1 << PB7);  // MOSI, SCK as output
	DDRB &= ~(1 << PB6);  // MISO as input

	// Set SS as output (must be held high in master mode)
	DDRB |= (1 << PB4);

	// Enable SPI, set as master, configure mode, data order, and clock rate
	SPCR = (1 << SPE) | (1 << MSTR) | (dataOrder << DORD) | (mode << CPHA) | (clockRate & 0x03);

	// Set SPI2X in SPSR if needed for double speed
	if (clockRate & 0x04) {
		SPSR |= (1 << SPI2X);
		} else {
		SPSR &= ~(1 << SPI2X);
	}
}

void SPI_InitSlave(SPI_Mode_t mode, SPI_DataOrder_t dataOrder) {
	// Set MISO as output, MOSI, SCK, and SS as input
	DDRB |= (1 << PB6);  // MISO as output
	DDRB &= ~((1 << PB5) | (1 << PB7) | (1 << PB4));  // MOSI, SCK, and SS as input

	// Enable SPI, set as slave, configure mode, and data order
	SPCR = (1 << SPE) | (dataOrder << DORD) | (mode << CPHA);
}

void SPI_Transmit(uint8_t data) {
	// Start transmission by writing data to SPDR
	SPDR = data;

	// Wait for transmission to complete (SPIF set in SPSR)
	while (!(SPSR & (1 << SPIF)));
}

uint8_t SPI_Receive(void) {
	// Wait for reception to complete (SPIF set in SPSR)
	while (!(SPSR & (1 << SPIF)));

	// Return the received data from SPDR
	return SPDR;
}

uint8_t SPI_Transceive(uint8_t data) {
	// Load data into the SPI data register
	SPDR = data;

	// Wait for transmission/reception to complete
	while (!(SPSR & (1 << SPIF)));

	// Return the data received during transmission
	return SPDR;
}
