#include "user_header/user_main.h"

void user_initialize(){
	drv8256_init();
	user_adc_init();
	encoder_init();
	pid_init();
//	control_init();
	HAL_TIM_Base_Start_IT(&htim13);
	HAL_TIM_Base_Start_IT(&htim2);
}

void user_loop(){
	int16_t time=500;
	float duty_in_main=1;

	while(1){
	set_target_count(500);
	HAL_Delay(4000);
	set_target_count(3500);
	HAL_Delay(4000);
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
		encoder_update();
		float output=pid_calc_output();
		drv8256_set_output(output);
	}
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle){
	HAL_GPIO_TogglePin (LED1_GPIO_Port, LED1_Pin);
	}
