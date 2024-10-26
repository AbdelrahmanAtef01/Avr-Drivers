#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include"util/delay.h"
#include"key_pad_cfg.h"

#define PRESSED (uint8_t)0
#define NOT_PRESSED (uint8_t)1


typedef struct{
	uint8_t port;
	uint8_t pin;
} KEY_PAD_PIN;

KEY_PAD_PIN column_pins[COLUMNS_NUMBER] ={COL_1_PIN,COL_2_PIN,COL_3_PIN,COL_4_PIN,
										COL_5_PIN,COL_6_PIN,COL_7_PIN,COL_8_PIN,COL_9_PIN,
										COL_10_PIN};

KEY_PAD_PIN row_pins[ROWS_NUMBER] ={ROW_1_PIN,ROW_2_PIN,ROW_3_PIN,ROW_4_PIN,
										ROW_5_PIN,ROW_6_PIN,ROW_7_PIN,ROW_8_PIN,ROW_9_PIN,
										ROW_10_PIN};

uint8_t button_values[COLUMNS_NUMBER][ROWS_NUMBER]=
{{BUTTON_0_0_ ,BUTTON_0_1_,BUTTON_0_2_,BUTTON_0_3_,BUTTON_0_4_,
  BUTTON_0_5_,BUTTON_0_6_,BUTTON_0_7_,BUTTON_0_8_,BUTTON_0_9_,},
 {BUTTON_1_0_ ,BUTTON_1_1_,BUTTON_1_2_,BUTTON_1_3_,BUTTON_1_4_,
  BUTTON_1_5_,BUTTON_1_6_,BUTTON_1_7_,BUTTON_1_8_,BUTTON_1_9_,},
 {BUTTON_2_0_ ,BUTTON_2_1_,BUTTON_2_2_,BUTTON_2_3_,BUTTON_2_4_,
  BUTTON_2_5_,BUTTON_2_6_,BUTTON_2_7_,BUTTON_2_8_,BUTTON_2_9_,},
 {BUTTON_3_0_ ,BUTTON_3_1_,BUTTON_3_2_,BUTTON_3_3_,BUTTON_3_4_,
  BUTTON_3_5_,BUTTON_3_6_,BUTTON_3_7_,BUTTON_3_8_,BUTTON_3_9_,},
 {BUTTON_4_0_ ,BUTTON_4_1_,BUTTON_4_2_,BUTTON_4_3_,BUTTON_4_4_,
  BUTTON_4_5_,BUTTON_4_6_,BUTTON_4_7_,BUTTON_4_8_,BUTTON_4_9_,},
 {BUTTON_5_0_ ,BUTTON_5_1_,BUTTON_5_2_,BUTTON_5_3_,BUTTON_5_4_,
  BUTTON_5_5_,BUTTON_5_6_,BUTTON_5_7_,BUTTON_5_8_,BUTTON_5_9_,},
 {BUTTON_6_0_ ,BUTTON_6_1_,BUTTON_6_2_,BUTTON_6_3_,BUTTON_6_4_,
  BUTTON_6_5_,BUTTON_6_6_,BUTTON_6_7_,BUTTON_6_8_,BUTTON_6_9_,},
 {BUTTON_7_0_ ,BUTTON_7_1_,BUTTON_7_2_,BUTTON_7_3_,BUTTON_7_4_,
  BUTTON_7_5_,BUTTON_7_6_,BUTTON_7_7_,BUTTON_7_8_,BUTTON_7_9_,},
 {BUTTON_8_0_ ,BUTTON_8_1_,BUTTON_8_2_,BUTTON_8_3_,BUTTON_8_4_,
  BUTTON_8_5_,BUTTON_8_6_,BUTTON_8_7_,BUTTON_8_8_,BUTTON_8_9_,},
 {BUTTON_9_0_ ,BUTTON_9_1_,BUTTON_9_2_,BUTTON_9_3_,BUTTON_9_4_,
  BUTTON_9_5_,BUTTON_9_6_,BUTTON_9_7_,BUTTON_9_8_,BUTTON_9_9_,},
};


void KEYPAD_vidInit(void)
{
	for(uint8_t i=0;i<COLUMNS_NUMBER;i++)
	{
		DIO_u8SetPinMode(column_pins[i].port,column_pins[i].pin,OUTPUT);
	}
	for(uint8_t i=0;i<ROWS_NUMBER;i++)
	{
		DIO_u8SetPinMode(row_pins[i].port,row_pins[i].pin,INPUT);
		DIO_u8SetPullUpMode(row_pins[i].port,row_pins[i].pin,Enabled);
	}
	for(uint8_t current_column=0;current_column<COLUMNS_NUMBER;current_column++)
	{
		DIO_u8SetPinValue(column_pins[current_column].port,column_pins[current_column].pin,HIGH);
	}
}

void KEYPAD_vidGetPressedSwitch(uint8_t*pressed_switch)
{
	uint8_t pressed_key,out=0;
	for(uint8_t current_column=0;current_column<COLUMNS_NUMBER;current_column++)
	{
		DIO_u8SetPinValue(column_pins[current_column].port,column_pins[current_column].pin,LOW);
		for(uint8_t current_row=0;current_row<ROWS_NUMBER;current_row++)
		{
			DIO_u8GetPinValue(row_pins[current_row].port,row_pins[current_row].pin,&pressed_key);
			if(pressed_key==PRESSED)
			{
				_delay_ms(20);
				while(pressed_key==PRESSED)
				{
					DIO_u8GetPinValue(row_pins[current_row].port,row_pins[current_row].pin,&pressed_key);
				}
#if KEYPAD_MODE == 1
				out=button_values[current_column][current_row];
#elif KEYPAD_MODE == 0
				out=current_column*10+current_row;
#else
#error	KEYPAD_MODE DEFINING REQUIRED
#endif
				_delay_ms(20);
			}
		}
		DIO_u8SetPinValue(column_pins[current_column].port,column_pins[current_column].pin,HIGH);
	}
	*pressed_switch = out;
}

