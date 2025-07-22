#include "stm32f10x.h"    // Device header
#include "Delay.h"


void LED_init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}

void Key_init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef G2;
	G2.GPIO_Mode = GPIO_Mode_IPU;
	G2.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	G2.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &G2);
	
}

uint8_t Key_Getnum(){
	uint8_t num = 0;
	
	if( GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0 ){
		Delay_ms(20);
		while( GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0 );
		Delay_ms(20);
		num = 1;
	}
	
	if( GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0 ){
		Delay_ms(20);
		while( GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0 );
		Delay_ms(20);
		num = 2;
	}
	
	return num;
}


void LED1_ON(){
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED2_ON(){
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED1_OFF(){
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED2_OFF(){
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED1_TURN(){
	if( GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0 ){
		LED1_OFF();
	}else{
		LED1_ON();
	}
	
}

void LED2_TURN(){
	if( GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0 ){
		LED2_OFF();
	}else{
		LED2_ON();
	}
}
