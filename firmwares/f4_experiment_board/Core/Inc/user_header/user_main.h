#ifndef USER_MAIN_H_INCLUDED
#define USER_MAIN_H_INCLUDED
//include-----------------------------------------
#include "tim.h"
#include "user_header/servo.h"
#include "user_header/user_adc.h"
#include "user_header/encoder.h"
#include "user_header/drive.h"
#include "user_header/servo.h"
//Macro definition--------------------------------

//Type definition---------------------------------

//Prototype declaration---------------------------
void user_initialize(void);
void user_loop(void);
#endif/*USER_MAIN_H_INCLUDED*/
