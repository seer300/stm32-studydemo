#include "stm32f10x.h" // Device header

int count = 0;

void CountSensor_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Pin = GPIO_Pin_14;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);

	EXTI_InitTypeDef exti;
	exti.EXTI_Line = EXTI_Line14;
	exti.EXTI_LineCmd = ENABLE;
	exti.EXTI_Mode = EXTI_Mode_Interrupt;
	exti.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&exti);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitTypeDef nvic;
	nvic.NVIC_IRQChannel = EXTI15_10_IRQn;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	nvic.NVIC_IRQChannelPreemptionPriority = 1;
	nvic.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&nvic);
}

void EXTI15_10_IRQHandler()
{
	if (EXTI_GetITStatus(EXTI_Line14) == 1)
	{
		count++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}

int getCount(){
	return count;
};
