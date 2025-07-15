#include "stm32f10x.h"                  // Device header
#include "Delay.h"




int main(){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructB;
	GPIO_InitStructB.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructB.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructB.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructB);


	while(1){	
		GPIO_WriteBit(GPIOB, GPIO_Pin_12, 0);
		GPIO_Write(GPIOA, ~0x0001);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0002);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0004);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0008);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0010);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0020);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0040);
		Delay_ms(200);
		GPIO_Write(GPIOA, ~0x0080);
		Delay_ms(200);
	}
}
