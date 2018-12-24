#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "remote.h"
#include "bmp180.h" 
#include "timer.h"
/************************************************
 ALIENTEK精英STM32开发板实验27
 红外遥控 实验    
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


 int main(void)
 {	 
	u8 key;
	int wash_flag = 0;
	int Infra_flag = 0;
	int Press_flag = 0;
	int state = 0;
	int direction = 0;
	int flag = 0;
	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();	 	
	Remote_Init();			//红外接收初始化
	BMP_Init();
	BMP_ReadCalibrationData();	 
 	TIM3_PWM_Init(899,0);	 //不分频。PWM频率=72000000/900=80Khz 		 	  		    							  
	while(1)
	{
		delay_ms(10);
		key=Remote_Scan();
		if(flag == 1)
		{	
			switch(key)
				{
								 
					case 162:TIM_SetCompare2(TIM3,800);break;	    
					case 98:TIM_SetCompare2(TIM3,700);break;	
					case 226:TIM_SetCompare2(TIM3,600);break;
					case 34:TIM_SetCompare2(TIM3,500);break;
					case 2:TIM_SetCompare2(TIM3,400);break;		 						  
					case 194:TIM_SetCompare2(TIM3,300);break;	   						  
					case 224:TIM_SetCompare2(TIM3,200);break;		  
					case 168:TIM_SetCompare2(TIM3,100);break;		   
					//case 144:TIM_SetCompare2(TIM3,100);break;		    
					default:break;		 
				}
		}else
		{
			TIM_SetCompare2(TIM3,900);
		}
		
		BMP_UncompemstatedToTrue();
		printf("\r\nkey:%d,%d,%d,%d\r\n",KEY0,KEY1,KEY2,KEY3);
		printf("\r\nPress:%ld\r\n",bmp180.p);
		if(key == 144)
		{
			wash_flag = !wash_flag;
		}
		if(wash_flag == 1)
		{
			LED4 = 1;
		}else
		{
			LED4 = 0;
		}
		
		if(key==56)
		{
			flag = 1;
		}else if(key == 152)
		{
			flag = 0;
			//TIM_SetCompare2(TIM3,0);
		}
		if(flag == 1)
		{
			Start();
		}else
		{
			End();
		}				
		
		if(KEY0==1&&KEY1==1&&KEY2==1&&KEY3==1)
		{
			Infra_flag = 1;
		}else
		{
			Infra_flag = 0;
		}
		if(bmp180.p>100000)
		{
			Press_flag = 1;
		}else
		{
			Press_flag = 0;
		}
		if(key==104)
		{
			state = 1;
		}else if(key==176)
		{
			state = 2;
		}
		
		if(Press_flag == 1&&state == 1&&flag == 1)
		{
			LED5 = 0;
			if(key==24)
			{	 
				Forward();
			}else if(key==74)
			{
				Backward();
			}else if(key==16)
			{
				Left();
			}else if(key==90)
			{
				Right();
			}
			else delay_ms(200);
		}
		else if(Press_flag == 1&&state == 2&&flag == 1)
		{
			LED5 = 0;
			Forward();
			if(KEY4 == 0)
			{
				if(direction==0)
				{
					Model_One();
				}else
				{
					Model_Two();
				}
				direction = !direction;
			}
		}	 
		else
		{
			LED5 = 1;
		}
	}
}





