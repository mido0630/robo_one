#ifndef USER_ADC_H_INCLUDED
#define USER_ADC_H_INCLUDED

//include-----------------------------------------
#include "adc.h"
#include "dma.h"
#include "tim.h"

//Macro definition--------------------------------
#define CONVERSION_CHANNEL_NUM 6
#define ADC_PA4 0
#define ADC_PA5 1
#define ADC_PA6 2
#define ADC_PA7 3
#define ADC_PB0 4
#define ADC_PB1 5

//Type definition---------------------------------

//Prototype declaration---------------------------
void user_adc_init(void);
uint16_t adc_read_from(uint8_t target);

#endif/*USER_ADC_H_INCLUDED*/
