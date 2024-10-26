#ifndef _TMR1_CONFIG_H
#define _TMR1_CONFIG_H

#include "../../CONFIG/CPU_Configuration.h"

// Define Timer1 modes
#define TMR1_MODE_NORMAL      0
#define TMR1_MODE_CTC         1
#define TMR1_MODE_PWM_FAST    2
#define TMR1_MODE_PWM_PHASE   3

// Define Clock Source (Prescaler values)
#define TMR1_PRESCALER_NO     1
#define TMR1_PRESCALER_8      2
#define TMR1_PRESCALER_64     3
#define TMR1_PRESCALER_256    4
#define TMR1_PRESCALER_1024   5

// Choose the default timer mode and prescaler for Timer1
#define TMR1_DEFAULT_MODE            TMR1_MODE_PWM_FAST
#define TMR1_DEFAULT_PRESCALER       TMR1_PRESCALER_256

#endif /* _TMR1_CONFIG_H */


