#include "led.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK ��ӢSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_12;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_ResetBits(GPIOB,GPIO_Pin_5);						 //PB.5 �����
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);						 //PB.5 �����

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_9|GPIO_Pin_5|GPIO_Pin_6;	    		 //LED1-->PE.5 �˿�����, �������
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_ResetBits(GPIOC,GPIO_Pin_1); 						 //PE.5 ����� 
 GPIO_ResetBits(GPIOC,GPIO_Pin_5); 						 //PE.5 �����
 GPIO_ResetBits(GPIOC,GPIO_Pin_6); 						 //PE.5 �����
 GPIO_ResetBits(GPIOC,GPIO_Pin_9); 						 //PE.5 �����
	
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

