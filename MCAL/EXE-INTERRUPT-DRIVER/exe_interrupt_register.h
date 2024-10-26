#ifndef MCAL_EXTERNAL_INTERRUPT_DRIVER_EXE_INTERRUPT_REGISTER_H_
#define MCAL_EXTERNAL_INTERRUPT_DRIVER_EXE_INTERRUPT_REGISTER_H_

#define MCUCR  (*((volatile uint8_t*)0x55))
#define MCUCSR (*((volatile uint8_t*)0x54))
#define GICR   (*((volatile uint8_t*)0x5B))
#define GIFR   (*((volatile uint8_t*)0x5A))

#endif
