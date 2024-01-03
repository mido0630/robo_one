#include "user_header/user_main.h"

void user_initialize(){
	drv8256_init();
	user_adc_init();
	encoder_init();
//	control_init();
	HAL_TIM_Base_Start_IT(&htim13);
	HAL_TIM_Base_Start_IT(&htim2);
}

void user_loop(){
	int count = 0, max_step = 10000-1, nagative_flag = 0;
	while(1){
		if(count > max_step){
		 nagative_flag = 1;
		 count = max_step;
		}
		else if(count < 0){
		  nagative_flag = 0;
		  count = 0;
		}
		if(nagative_flag) count--;
		else count+=4;
//		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 2250/2);
//		if(HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_Value, 6)!=HAL_OK)Error_Handler();
	    HAL_Delay(1);
	}
}

void timer_interrupt_1(){
	;
}

void timer_interrupt_2(){
//	HAL_GPIO_TogglePin (LED1_GPIO_Port, LED1_Pin);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if( htim->Instance == TIM13 ){
		//2kHz
		timer_interrupt_1();
	}
	if( htim->Instance == TIM2 ){
		//20kHz
		timer_interrupt_2();
	}
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle){
	HAL_GPIO_TogglePin (LED1_GPIO_Port, LED1_Pin);
}
