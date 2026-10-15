#include "main.h"
#include "TLC5925.h"

/********************************************************************************************/
// 此代码适用STM32F103，一个TLC5925控制两个共阴数码管，若不符合，请修改下面的宏

#define CLK_PIN			GPIO_PIN_3
#define SDI_PIN			GPIO_PIN_4
#define LE_PIN			GPIO_PIN_5
#define OE_PIN			GPIO_PIN_6

#define CLK_HIGH		HAL_GPIO_WritePin(GPIOA, CLK_PIN, GPIO_PIN_SET); 
#define CLK_LOW			HAL_GPIO_WritePin(GPIOA, CLK_PIN, GPIO_PIN_RESET); 
#define SDI_HIGH		HAL_GPIO_WritePin(GPIOA, SDI_PIN, GPIO_PIN_SET);
#define SDI_LOW			HAL_GPIO_WritePin(GPIOA, SDI_PIN, GPIO_PIN_RESET); 
#define LE_HIGH			HAL_GPIO_WritePin(GPIOA, LE_PIN, GPIO_PIN_SET); 
#define LE_LOW			HAL_GPIO_WritePin(GPIOA, LE_PIN, GPIO_PIN_RESET);
#define OE_HIGH			HAL_GPIO_WritePin(GPIOA, OE_PIN, GPIO_PIN_SET); 
#define OE_LOW			HAL_GPIO_WritePin(GPIOA, OE_PIN, GPIO_PIN_RESET); 

#define	Delay			HAL_Delay(1);

/**@NOTE   发送字节函数，两字节
  *@RETURN 无
  */
void TLC5925_Us(void)
{
	TLC5925_Send(0x4F66);
}

/********************************************************************************************/

void TLC5925_Init(void)
{
	LE_LOW;
	OE_HIGH;  
	SDI_LOW;
	CLK_LOW;
}

void TLC5925_Send(uint16_t u16_data)
{
	int8_t i;
	
	for (i = 15; i >= 0; i--)
	{
		if (u16_data & (1 << i))  
		{
			SDI_HIGH;
			Delay;
		}
		else
		{
			SDI_LOW;
			Delay;
		}	
		CLK_HIGH;	
		Delay		
		CLK_LOW;		
		Delay;		
	}
		LE_HIGH;
		Delay;		
		LE_LOW;
		Delay;
		OE_LOW;
		Delay;	
}
