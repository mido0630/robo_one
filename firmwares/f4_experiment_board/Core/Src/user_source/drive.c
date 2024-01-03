#include "user_header/drive.h"

uint16_t PWM_COUNTER_PERIOD=0;

void drv8256_init(){
	//DRV8256用PWM出力を初期値0で開始
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	//DRV8256のENABLEピンをHIGHで初期化
	HAL_GPIO_WritePin(DCM_ENBALE_GPIO_Port,DCM_ENBALE_Pin,GPIO_PIN_SET);
	//PWMの最大カウントをglobal変数に代入
	PWM_COUNTER_PERIOD=htim1.Init.Period;
}

void drv8256_set_output(float duty){
	//入力はduty(-1.0f~1.0f)
	if(duty>0.0) HAL_GPIO_WritePin(DCM_ENBALE_GPIO_Port,DCM_ENBALE_Pin,GPIO_PIN_SET);
	else{
		HAL_GPIO_WritePin(DCM_ENBALE_GPIO_Port,DCM_ENBALE_Pin,GPIO_PIN_RESET);
		duty=-1.0*duty;
	}
	if(duty>1.0)duty=1.0;
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (uint16_t)(duty*(float)PWM_COUNTER_PERIOD));
}
