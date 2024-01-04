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
	int16_t time=500;
	float duty_in_main=1;
	while(1){
	drv8256_set_output(duty_in_main);
	HAL_Delay(time);
	drv8256_set_output(-1.0*duty_in_main);
	HAL_Delay(time);
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
