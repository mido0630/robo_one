#include "user_header/user_main.h"

void user_initialize(){
	//DRV8256のPWMピン
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	//DRV8256のENABLEピン
	HAL_GPIO_WritePin(DCM_ENBALE_GPIO_Port,DCM_ENBALE_Pin,GPIO_PIN_SET);
	//PWM start
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
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
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 2250/2);
	    HAL_Delay(1);
	}
}

void timer_interrupt_1kHz(){
	;
}

void timer_interrupt_20kHz(){
	;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if( htim->Instance == TIM13 ){
		//1kHz
		timer_interrupt_1kHz();
	}
	if( htim->Instance == TIM14 ){
		//4kHz
		timer_interrupt_20kHz();
	}
}
