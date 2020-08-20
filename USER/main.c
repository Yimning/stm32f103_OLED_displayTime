#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "oled.h"
#include "rtc.h"  
/************************************************
 ALIENTEK 战舰STM32F103开发板实验12
 OLED显示实验 
************************************************/
	
 int main(void)
 {	
	u8 t=0;
	delay_init();	    	 //延时函数初始化	  
	RTC_Init();	  			//RTC初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
 	LED_Init();			     //LED端口初始化
	OLED_Init();			//初始化OLED      
  OLED_ShowString(0,0,"ALIENTEK",24);  
  
	//OLED_Refresh_Gram();		//更新显示到OLED 

	while(1) 
	{		
 		OLED_Refresh_Gram();
		delay_ms(500);
		LED0=!LED0;
		if(t!=calendar.sec)
		{
			t=calendar.sec;
			OLED_ShowNum(0,24,calendar.w_year,4,12);  //年
			  OLED_ShowString(24,24, "-",12); 
			if(calendar.w_month<10) //小于10时显示补0  如09
			 {	
				 OLED_ShowNum(30,24,0,1,12);
			   OLED_ShowNum(36,24,calendar.w_month,1,12);//月
			 }else OLED_ShowNum(36,24,calendar.w_month,2,12);  
		  	OLED_ShowString(42,24, "-",12); 
			 if(calendar.w_date<10)  //日
			 {
				 OLED_ShowNum(48,24,0,1,12);
		  	 OLED_ShowNum(54,24,calendar.w_date,1,12);  
			 }else OLED_ShowNum(48,24,calendar.w_date,2,12);  
			switch(calendar.week)
			{
				case 0:   //显示星期几
					 	OLED_ShowString(64,24,"Sunday",12);  
					break;
				case 1:
						OLED_ShowString(64,24,"Monday",12);
					break;
				case 2:
						OLED_ShowString(64,24,"Tuesday",12);
					break;
				case 3:
					 OLED_ShowString(64,24,"Wednesday",12);
					break;
				case 4:
					OLED_ShowString(64,24,"Thursday",12);
					break;
				case 5:
					OLED_ShowString(64,24,"Friday",12);
					break;
				case 6:
					OLED_ShowString(64,24,"Saturday",12);
					break;  
			}
			if(calendar.hour<10)
			{
			 OLED_ShowNum(0,36,0,1,16);
			 OLED_ShowNum(8,36,calendar.hour,1,16);
			}else 
			OLED_ShowNum(0,36,calendar.hour,2,16);
			
			OLED_ShowString(16,36,":",16);
			
			if(calendar.min<10)
			{
			 OLED_ShowNum(24,36,0,1,16);
			 OLED_ShowNum(32,36,calendar.min,1,16);
			}else 			
		  OLED_ShowNum(24,36,calendar.min,2,16);  
			
    	OLED_ShowString(40,36,":",16);
			
			if(calendar.sec<10)
			{
			 OLED_ShowNum(48,36,0,1,16);
			 OLED_ShowNum(56,36,calendar.sec,1,16);
			}else OLED_ShowNum(48,36,calendar.sec,2,16);  
			
		}	LED0=!LED0;
	//	delay_ms(10);								  
	};  
		
}

