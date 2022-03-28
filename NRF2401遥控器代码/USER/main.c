//#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "oled.h"
#include "usart.h"
#include "24l01.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 

 int main(void)
 {	 
	char Display_str[50]="";
	float pitch,roll,yaw; 		//ŷ����
	delay_init();				//��ʱ��ʼ�� 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);     //�ر�JTAG
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ500000
//	LED_Init();
	OLED_Init();

	MPU_Init();					//��ʼ��MPU6050
	while(mpu_dmp_init())
 	{
		OLED_ShowString(0,0,"6050 Error");
			printf("6050 Error\r\n");
		OLED_Refresh_Gram();
		delay_ms(200);
	}
	
// 	NRF24L01_Init();    		//��ʼ��NRF24L01  
//	while(NRF24L01_Check())
//	{
//		OLED_ShowString(0,0,"24L01 Error");
//		OLED_Refresh_Gram();
// 		delay_ms(200);
//	}
	OLED_Clear();
 	while(1)
	{

		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{
			sprintf(Display_str, "pitch:%.2f",pitch);
			printf("pitch:%.2f\r\n\r\n",pitch);
			OLED_ShowString(0,16,Display_str);
			sprintf(Display_str, "roll: %.2f", roll);
			OLED_ShowString(0,28,Display_str);			
			sprintf(Display_str, "yaw:  %.2f",  yaw);
			OLED_ShowString(0,40,Display_str);
			OLED_Refresh_Gram();
		}
		delay_ms(100);
	} 	
}
 


