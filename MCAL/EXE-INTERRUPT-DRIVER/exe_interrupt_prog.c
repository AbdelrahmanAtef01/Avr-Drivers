#include"../../libraries/std_types.h"
#include"../../libraries/bit_math.h"
#include"../dio_driver/dio_int.h"
#include "../global_interrupt_driver/global_interrupt_int.h"
#include"exe_interrupt_register.h"
#include"exe_interrupt_config.h"
#include"exe_interupt_int.h"

typedef struct{
	uint8_t port;
	uint8_t pin;
} EXE_INTERRUPT_PIN;

EXE_INTERRUPT_PIN EXE_INTERRUPT_PINS[3]={EXE_INTERRUPT_0,EXE_INTERRUPT_1,EXE_INTERRUPT_2};

void (*vector_1)(void) = NULL;
void (*vector_2)(void) = NULL;
void (*vector_3)(void) = NULL;

void EXE_INTERRUPT_vidExeInterruptInit(uint8_t interrupt, uint8_t interrupt_mode)
{
	EXE_INTERRUPT_vidExeInterruptMode(interrupt,interrupt_mode);
	switch(interrupt)
	{
	case INTERRUPT_0:
		DIO_u8SetPinMode(EXE_INTERRUPT_PINS[0].port,EXE_INTERRUPT_PINS[0].pin,INPUT);
		break;
	case INTERRUPT_1:
		DIO_u8SetPinMode(EXE_INTERRUPT_PINS[1].port,EXE_INTERRUPT_PINS[1].pin,INPUT);
		break;
	case INTERRUPT_2:
		DIO_u8SetPinMode(EXE_INTERRUPT_PINS[2].port,EXE_INTERRUPT_PINS[2].pin,INPUT);
		break;
	case ALL_INTERRUPTS:
		DIO_u8SetPinMode(EXE_INTERRUPT_PINS[0].port,EXE_INTERRUPT_PINS[0].pin,INPUT);
		DIO_u8SetPinMode(EXE_INTERRUPT_PINS[1].port,EXE_INTERRUPT_PINS[1].pin,INPUT);
		DIO_u8SetPinMode(EXE_INTERRUPT_PINS[2].port,EXE_INTERRUPT_PINS[2].pin,INPUT);
		break;
	}
	GLOBAL_INTERRUPT_vidGlobalInterruptEnable(ENABLED);
	EXE_INTERRUPT_vidExeInterruptEnable(interrupt,ENABLED);
}
void EXE_INTERRUPT_vidExeInterruptSetPullUpMode(uint8_t interrupt)
{
	switch(interrupt)
	{
	case INTERRUPT_0:
		DIO_u8SetPullUpMode(EXE_INTERRUPT_PINS[0].port,EXE_INTERRUPT_PINS[0].pin,ENABLED);
		break;
	case INTERRUPT_1:
		DIO_u8SetPullUpMode(EXE_INTERRUPT_PINS[1].port,EXE_INTERRUPT_PINS[1].pin,ENABLED);
		break;
	case INTERRUPT_2:
		DIO_u8SetPullUpMode(EXE_INTERRUPT_PINS[2].port,EXE_INTERRUPT_PINS[2].pin,ENABLED);
		break;
	case ALL_INTERRUPTS:
		DIO_u8SetPullUpMode(EXE_INTERRUPT_PINS[0].port,EXE_INTERRUPT_PINS[0].pin,ENABLED);
		DIO_u8SetPullUpMode(EXE_INTERRUPT_PINS[1].port,EXE_INTERRUPT_PINS[1].pin,ENABLED);
		DIO_u8SetPullUpMode(EXE_INTERRUPT_PINS[2].port,EXE_INTERRUPT_PINS[2].pin,ENABLED);
		break;
	}
}
void EXE_INTERRUPT_vidExeInterruptEnable(uint8_t interrupt, uint8_t mode)
{
	if(mode==ENABLED)
	{
	switch(interrupt)
	{
	case INTERRUPT_0:
		SET_BIT(GICR,6);
		break;
	case INTERRUPT_1:
		SET_BIT(GICR,7);
		break;
	case INTERRUPT_2:
		SET_BIT(GICR,5);
		break;
	case ALL_INTERRUPTS:
		SET_BIT(GICR,5);
		SET_BIT(GICR,6);
		SET_BIT(GICR,7);
		break;
	}
	}else if(mode==DISABLED)
	{
		switch(interrupt)
		{
		case INTERRUPT_0:
			CLR_BIT(GICR,6);
			break;
		case INTERRUPT_1:
			CLR_BIT(GICR,7);
			break;
		case INTERRUPT_2:
			CLR_BIT(GICR,5);
			break;
		case ALL_INTERRUPTS:
			CLR_BIT(GICR,5);
			CLR_BIT(GICR,6);
			CLR_BIT(GICR,7);
			break;
		}
	}
}
void EXE_INTERRUPT_vidExeInterruptMode(uint8_t interrupt, uint8_t interrupt_mode)
{
	uint8_t first_bit,second_bit;
	switch(interrupt_mode)
	{
	case RISING_EDGE:
		first_bit=1;second_bit=1;break;
	case FALLING_EDGE:
		first_bit=1;second_bit=0;break;
	case LOGICAL_CHANGE:
		first_bit=0;second_bit=1;break;
	case LOW_LEVEL:
		first_bit=0;second_bit=0;break;
	}
	switch(interrupt)
	{
	case INTERRUPT_0:
		if(first_bit==1)SET_BIT(MCUCR,1);
		else if(first_bit==0)CLR_BIT(MCUCR,1);
		if(second_bit==1)SET_BIT(MCUCR,0);
		else if(second_bit==0)CLR_BIT(MCUCR,0);
		break;
	case INTERRUPT_1:
		if(first_bit==1)SET_BIT(MCUCR,3);
		else if(first_bit==0)CLR_BIT(MCUCR,3);
		if(second_bit==1)SET_BIT(MCUCR,2);
		else if(second_bit==0)CLR_BIT(MCUCR,2);
		break;
	case INTERRUPT_2:
		if(interrupt_mode==RISING_EDGE||interrupt_mode==FALLING_EDGE)
		{
		if(second_bit==1)SET_BIT(MCUCSR,6);
		else if(second_bit==0)CLR_BIT(MCUCSR,6);
		}
		break;
	case ALL_INTERRUPTS:
		if(interrupt_mode==RISING_EDGE||interrupt_mode==FALLING_EDGE)
		{
			if(first_bit==1){SET_BIT(MCUCR,1);SET_BIT(MCUCR,3);}
			else if(first_bit==0){CLR_BIT(MCUCR,1);CLR_BIT(MCUCR,3);}
			if(second_bit==1){SET_BIT(MCUCR,0);SET_BIT(MCUCR,2);SET_BIT(MCUCSR,6);}
			else if(second_bit==0){CLR_BIT(MCUCR,0);CLR_BIT(MCUCR,2);CLR_BIT(MCUCSR,6);}
		}
		break;
	}

}

void EXE_INTERRUPT_vidSetCallBack(uint8_t interrupt, void (*func)(void))
{
	switch(interrupt)
	{
	case INTERRUPT_0:
		vector_1=func;
		break;
	case INTERRUPT_1:
		vector_2=func;
		break;
	case INTERRUPT_2:
		vector_3=func;
		break;
	case ALL_INTERRUPTS:
		vector_1=func;
		vector_2=func;
		vector_3=func;
		break;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(vector_1!=NULL)vector_1();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(vector_1!=NULL)vector_2();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(vector_1!=NULL)vector_3();
}
