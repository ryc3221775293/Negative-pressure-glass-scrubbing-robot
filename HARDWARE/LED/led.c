#include "led.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK 精英STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOE, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_12;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_ResetBits(GPIOB,GPIO_Pin_5);						 //PB.5 输出高
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);						 //PB.5 输出高

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_9|GPIO_Pin_5|GPIO_Pin_6;	    		 //LED1-->PE.5 端口配置, 推挽输出
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_ResetBits(GPIOC,GPIO_Pin_1); 						 //PE.5 输出高 
 GPIO_ResetBits(GPIOC,GPIO_Pin_5); 						 //PE.5 输出高
 GPIO_ResetBits(GPIOC,GPIO_Pin_6); 						 //PE.5 输出高
 GPIO_ResetBits(GPIOC,GPIO_Pin_9); 						 //PE.5 输出高
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	    		 //LED1-->PE.5 ????, ????
 GPIO_Init(GPIOE, &GPIO_InitStructure);	  				 //???? ,IO????50MHz
 GPIO_SetBits(GPIOE,GPIO_Pin_5); 						 //PE.5 ???
}
void Backward(void)
{
	LED0 = 1;
	LED1 = 0;
	LED2 = 1;
	LED3 = 0;
	//LED4 = 1;
}
void Forward(void)
{
	LED0 = 0;
	LED1 = 1;
	LED2 = 0;
	LED3 = 1;
	//LED4 = 1;
}
void Right(void)
{
	LED0 = 0;
	LED1 = 0;
	LED2 = 1;
	LED3 = 0;
	//LED4 = 1;
}
void Left(void)
{
	LED0 = 1;
	LED1 = 0;
	LED2 = 0;
	LED3 = 0;
	//LED4 = 1;
}
void Start(void)
{
	//LED4 = 1;
}
void End(void)
{
	LED0 = 0;
	LED1 = 0;
	LED2 = 0;
	LED3 = 0;
	LED4 = 0;
}
void Model_One(void)
{
	Backward();
	delay_ms(1000);
	Right();
	delay_ms(5000);
}
void Model_Two(void)
{
	Backward();
	delay_ms(1000);
	Left();
	delay_ms(5000);
}

