#ifndef USART_ADDRESS_H_
#define USART_ADDRESS_H_

// USART I/O Data Register
#define UDR     (*(volatile uint8_t*)0x2C)

// USART Control and Status Registers
#define UCSRA   (*(volatile uint8_t*)0x2B)
#define UCSRB   (*(volatile uint8_t*)0x2A)
#define UCSRC   (*(volatile uint8_t*)0x40)

// Baud Rate Registers
#define UBRRL   (*(volatile uint8_t*)0x29)
#define UBRRH   (*(volatile uint8_t*)0x40)

// Bit positions for UCSRA
#define RXC     7   // Receive Complete
#define TXC     6   // Transmit Complete
#define UDRE    5   // Data Register Empty

// Bit positions for UCSRB
#define RXEN    4   // Receiver Enable
#define TXEN    3   // Transmitter Enable
#define RXCIE   7   // RX Complete Interrupt Enable
#define TXCIE   6   // TX Complete Interrupt Enable

// Bit positions for UCSRC
#define URSEL   7   // Register Select (1 for UCSRC, 0 for UBRRH)
#define UCSZ0   1   // Character Size bit 0
#define UCSZ1   2   // Character Size bit 1

#endif /* USART_ADDRESS_H_ */
