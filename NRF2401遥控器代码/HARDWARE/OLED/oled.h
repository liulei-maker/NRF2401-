#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"

//-----------------OLED�˿ڶ���---------------- 

#define OLED_SCLK_Clr()  PAout(12)=0  //SCL
#define OLED_SCLK_Set()  PAout(12)=1   //SCL

#define OLED_SDIN_Clr()  PAout(11)=0   //SDA
#define OLED_SDIN_Set()  PAout(11)=1   //SDA

#define OLED_RST_Clr() PAout(8)=0   //RST
#define OLED_RST_Set() PAout(8)=1   //RST

#define OLED_RS_Clr() PBout(15)=0    //DC
#define OLED_RS_Set() PBout(15)=1    //DC

#define OLED_CS_Clr() PBout(14)=0    //CS
#define OLED_CS_Set() PBout(14)=1    //CS

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����
//OLED�����ú���
void OLED_WR_Byte(u8 dat,u8 cmd);	 		//��OLEDд��һ���ֽڡ�   
void OLED_Display_On(void);						//����OLED��ʾ 
void OLED_Display_Off(void);					//�ر�OLED��ʾ  
void OLED_Refresh_Gram(void);		   		//ˢ����ʾ		   		    
void OLED_Init(void);									//��ʼ��OLED
void OLED_Clear(void);								//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	
void OLED_DrawPoint(u8 x,u8 y,u8 t);	//����
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);			//��ָ��λ����ʾһ���ַ�,���������ַ�
void OLED_ShowNumber(u8 x,u8 y,u32 num,u8 len,u8 size);		//��ʾ2������
void OLED_ShowString(u8 x,u8 y,const char *p);							//��ʾ�ַ��� 
void OLED_ShowFloatNumber(u8 x,u8 y,float num,u8 len,u8 size,u8 fNum);//��ʾС��
#endif  
	 
