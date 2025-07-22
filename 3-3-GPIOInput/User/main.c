#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#include "LED.h"


uint8_t keynum;

int main(){
	LED_init();
	Key_init();

	while(1){	
		keynum = Key_Getnum();
		if( keynum == 1 ){
			LED1_TURN();
		}
		if( keynum == 2 ){
			LED2_TURN();
		}
		
	}
}
