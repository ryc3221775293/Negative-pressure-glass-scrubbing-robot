#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


#define KEY0  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)//��ȡ����1
#define KEY2  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//��ȡ����0
#define KEY3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)//��ȡ����1
#define KEY4  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)//��ȡ����1
void KEY_Init(void);//IO��ʼ��				    
#endif
