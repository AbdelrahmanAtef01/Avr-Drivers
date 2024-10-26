#ifndef MCAL_EXTERNAL_INTERRUPT_DRIVER_EXE_INTERUPT_INT_H_
#define MCAL_EXTERNAL_INTERRUPT_DRIVER_EXE_INTERUPT_INT_H_

/*macros to be used with mode param*/

#define ENABLED  (uint8_t)1
#define DISABLED (uint8_t)0

/*macros to be used with interrupt param*/

#define INTERRUPT_0    (uint8_t)0
#define INTERRUPT_1    (uint8_t)1
#define INTERRUPT_2    (uint8_t)2
#define ALL_INTERRUPTS (uint8_t)3

/*macros to be used with interrupt_mode param
 * in case of interrupt_2 or all_interrupts you can only use the rising or falling edge mode
 */

#define RISING_EDGE    (uint8_t)0
#define FALLING_EDGE   (uint8_t)1
#define LOGICAL_CHANGE (uint8_t)2
#define LOW_LEVEL      (uint8_t)3

void EXE_INTERRUPT_vidExeInterruptInit(uint8_t interrupt, uint8_t interrupt_mode);
void EXE_INTERRUPT_vidExeInterruptEnable(uint8_t interrupt, uint8_t mode);
void EXE_INTERRUPT_vidExeInterruptMode(uint8_t interrupt, uint8_t interrupt_mode);
void EXE_INTERRUPT_vidSetCallBack(uint8_t interrupt, void (*func)(void));
void EXE_INTERRUPT_vidExeInterruptSetPullUpMode(uint8_t interrupt);

#endif
