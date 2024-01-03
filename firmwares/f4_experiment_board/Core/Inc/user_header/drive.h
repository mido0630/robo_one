#ifndef DRIVE_H_INCLUDED
#define DRIVE_H_INCLUDED
//include-----------------------------------------
#include "tim.h"
//Macro definition--------------------------------

//Type definition---------------------------------

//Prototype declaration---------------------------
void drv8256_init(void);
void drv8256_set_output(float duty);
#endif/*DRIVE_H_INCLUDED*/
