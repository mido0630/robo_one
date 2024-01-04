#include "user_header/servo.h"

volatile struct_servo_status servo_status;

void pid_init(){
	servo_status.target=encoder_read_count();
	servo_status.prev=servo_status.target;
	servo_status.i_error=0;
	servo_status.p_gain=P_GAIN;
	servo_status.i_gain=I_GAIN;
	servo_status.d_gain=D_GAIN;
	servo_status.output_limit=1.0;
}
float output;
float pid_calc_output(){
	int current=encoder_read_count();
	servo_status.error = servo_status.target - current;
    int derivative = current - servo_status.prev;
    servo_status.prev = current;
    float output = ((servo_status.p_gain * servo_status.error)
    			+ (servo_status.i_gain * servo_status.i_error)
				+ (servo_status.d_gain * derivative));
    servo_status.i_error += servo_status.error;
    if(output>servo_status.output_limit)output=servo_status.output_limit;
    if(output<-1.0*servo_status.output_limit)output=-1.0*servo_status.output_limit;
    servo_status.output=-1.0*output;
    return servo_status.output;
}

void set_target_count(int32_t target){
	servo_status.target=target;
	servo_status.i_error=0;
}
