#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PCout(1)// PB5
#define LED1 PCout(5)// PE5
#define LED2 PCout(6)// PB5
#define LED3 PCout(9)// PE5	
#define LED4 PBout(12)// PE5
#define LED5 PEout(5)// PE5

void LED_Init(void);//��ʼ��
void Forward(void);
void Backward(void);
void Left(void);
void Right(void);
void Start(void);
void End(void);
void Model_One(void);
void Model_Two(void);
		 				    
#endif
