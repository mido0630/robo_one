#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
//include-----------------------------------------
#include "user_header/user_adc.h"
//Macro definition--------------------------------

//Type definition---------------------------------
struct encoder{
	int32_t current_count;//ENABLEでサーボ有効
	int32_t last_count;
	float current_deg;
	float last_deg;
} ;
//Prototype declaration---------------------------
void encoder_init(void);
void encoder_set_count(int32_t count);
int32_t encoder_read_count(void);
void encoder_update(void);
#endif/*ENCODER_H_INCLUDED*/
