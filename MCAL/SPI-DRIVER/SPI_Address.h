#ifndef SPI_ADDRESS_H_
#define SPI_ADDRESS_H_

// SPI Control Register
#define SPCR    (*(volatile uint8_t*)0x2D)
// SPI Status Register
#define SPSR    (*(volatile uint8_t*)0x2E)
// SPI Data Register
#define SPDR    (*(volatile uint8_t*)0x2F)

// Bit positions in SPCR
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

// Bit positions in SPSR
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#endif /* SPI_ADDRESS_H_ */
