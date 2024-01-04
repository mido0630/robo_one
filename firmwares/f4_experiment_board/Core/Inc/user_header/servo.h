#ifndef SERVO_H_INCLUDED
#define SERVO_H_INCLUDED
//include-----------------------------------------
#include "user_header/encoder.h"
//Macro definition--------------------------------
#define P_GAIN				0.01
#define I_GAIN				0.0
#define D_GAIN				-0.4
//Type definition---------------------------------
typedef struct {
	int32_t target;
	int32_t prev;
	int32_t error;
	int32_t i_error;
	float p_gain;
	float i_gain;
	float d_gain;
	float output_limit;
	float output;
}struct_servo_status;

//Prototype declaration---------------------------
void pid_init(void);
float pid_calc_output(void);
void set_target_count(int32_t count);
#endif/*SERVO_H_INCLUDED*/
