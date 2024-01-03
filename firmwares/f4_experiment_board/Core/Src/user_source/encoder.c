#include "user_header/encoder.h"

struct encoder potentio;
void encoder_init(void){
	potentio.current_count=adc_read_from(ADC_PA4);
	potentio.last_count=potentio.current_count;
	potentio.last_deg=0;
	potentio.last_deg=0;
}
void encoder_set_count(int32_t count){
	;
}
void encoder_read_count(int32_t count){
	;
}
void encoder_update(){
	potentio.last_count=potentio.current_count;
	potentio.current_count=adc_read_from(ADC_PA4);
}
