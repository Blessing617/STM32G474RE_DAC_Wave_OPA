#include "BACKGROUND.h"

void BackGround_Init(void)
{
	
	OLED_ShowChar(0,6,'&',2);
	
	OLED_ShowChar(16*4+8,0,'K',2);
	OLED_ShowChar(16*4+8,2,'K',2);
	OLED_ShowChar(16*4+8,4,'K',2);
	OLED_ShowChar(16*4+8,6,'K',2);
	
	OLED_ShowChar(120,0,'V',2);
	OLED_ShowChar(120,2,'V',2);
	OLED_ShowChar(120,4,'V',2);	
	OLED_ShowChar(120,6,'%',2);			
	
	OLED_ShowCN(8,0,12);		//正
	OLED_ShowCN(24,0,13);		//弦
	
	OLED_ShowCN(8,2,14);		//方
	OLED_ShowCN(24,2,2);		//波
	
	OLED_ShowCN(8,4,15);		//三
	OLED_ShowCN(24,4,16);		//角
	
	OLED_ShowCN(8,6,14);		//方
	OLED_ShowCN(24,6,2);		//波	
	
}

void freShow(double number,int wave)
{
	switch(wave)
	{
		case sine: OLED_ShowFloat(16*2+8,0,number,2); OLED_ShowChar(16*4+8,0,'K',2);break;
		case squ1: OLED_ShowFloat(16*2+8,2,number,2); OLED_ShowChar(16*4+8,2,'K',2);break;
		case tri : OLED_ShowFloat(16*2+8,4,number,2); OLED_ShowChar(16*4+8,4,'K',2);break;
		case squ2: OLED_ShowFloat(16*2+8,6,number,2); OLED_ShowChar(16*4+8,6,'K',2);break;
	}
}

void ampShow(double number,int wave)
{
	switch(wave)
	{
		case sine: OLED_ShowFloat_2f(120-32,0,number,2); break;
		case squ1: OLED_ShowFloat_2f(120-32,2,number,2); break;
		case tri : OLED_ShowFloat_2f(120-32,4,number,2); break;
		case squ2: OLED_ShowInt(120-24,6,number,2); break;
	}
}

void fre_ampShow(void)
{
	freShow(5,sine);
	freShow(5,squ1);
	freShow(5,tri);
	freShow(5,squ2);
	
	ampShow(3.3,sine);
	ampShow(3.3,squ1);
	ampShow(3.3,tri);
	ampShow(50,squ2);
	
}

void select(int wave)
{
	switch(wave)
	{
		case sine: 	OLED_ShowChar(0,0,'&',2);
					OLED_ShowChar(0,2,' ',2);
					OLED_ShowChar(0,4,' ',2);
					break;
		
		case squ1: 	OLED_ShowChar(0,2,'&',2);
					OLED_ShowChar(0,0,' ',2);
					OLED_ShowChar(0,4,' ',2);				
					break;
				   
		case tri : 	OLED_ShowChar(0,4,'&',2);
					OLED_ShowChar(0,0,' ',2);
					OLED_ShowChar(0,2,' ',2);		
					break;
	}
}
