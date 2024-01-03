#include "user_header/user_adc.h"

uint16_t adc_Value[CONVERSION_CHANNEL_NUM];
void user_adc_init(void){
//	main.c内、MX_DMA_Init();がMX_ADC1_Init();よりも後にあると正常にDMAが開始されない不具合あり
	if(HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_Value, CONVERSION_CHANNEL_NUM)!=HAL_OK)Error_Handler();
//	hdma_adc1.Instance->CCR &= ~(DMA_IT_TC | DMA_IT_HT);
}

uint16_t adc_read_from(uint8_t target){
	return adc_Value[target];
}
