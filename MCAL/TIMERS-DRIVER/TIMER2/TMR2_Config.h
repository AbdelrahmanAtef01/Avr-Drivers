#ifndef _TMR2_CONFIG_H
#define _TMR2_CONFIG_H

#include "../../CONFIG/CPU_Configuration.h"

// Define Timer modes
#define TMR2_MODE_NORMAL      0
#define TMR2_MODE_CTC         1
#define TMR2_MODE_PWM         2

// Define Clock Source (Prescaler values)
#define TMR2_PRESCALER_NO     1
#define TMR2_PRESCALER_8      2
#define TMR2_PRESCALER_32     3
#define TMR2_PRESCALER_64     4
#define TMR2_PRESCALER_128    5
#define TMR2_PRESCALER_256    6
#define TMR2_PRESCALER_1024   7

// Choose the timer mode and prescaler for your configuration
#define TMR2_MODE            TMR2_MODE_CTC
#define TMR2_PRESCALER       TMR2_PRESCALER_64

#endif /* _TMR2_CONFIG_H */
