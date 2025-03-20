#include "USART_Control.h"

double sinef=5.0,sinev=3.3;
double squf1=5.0,squv1=3.3;
double trif=5.0,triv=3.3;
double squf2=5.0,squr=50;

void USTART_Control(void)
{
	uint8_t Rx_data[100];
	if(MyUSART1_ReadLine(Rx_data))
    {   
	  HAL_TIM_Base_Stop(&htim6);
	  HAL_DAC_Stop_DMA(&hdac4,DAC_CHANNEL_1);	
		
      if(Rx_data[0]=='s'&& Rx_data[1]=='i'&&Rx_data[2]=='n')
	  {
		  sscanf((char*)Rx_data+4,"%lf,%lf",&sinef,&sinev);
		  
		  if(sinev>0&&sinev<=3.3)
		  {  
			TIM6_Init(sinef*100000.0);
			sin_Generation(sinev/3.3);
		  
			WaveStart(sine);
			freShow(sinef,sine);
			ampShow(sinev,sine);
			select(sine);
		  }
	  } 
	  
     else if(Rx_data[0]=='s'&& Rx_data[1]=='q'&&Rx_data[2]=='u'&&Rx_data[3]=='1')
	  {

		  sscanf((char*)Rx_data+5,"%lf,%lf",&squf1,&squv1);		
		  
		  if(squv1>0&&squv1<=3.3)
		  {			  
			TIM6_Init(squf1*100000.0);
			squ_Generation(squv1/3.3);
		  
			WaveStart(squ1);
			freShow(squf1,squ1);
			ampShow(squv1,squ1);
			select(squ1);
		  }
	  }
	  
     else if(Rx_data[0]=='t'&& Rx_data[1]=='r'&&Rx_data[2]=='i')
	  {
		  sscanf((char*)Rx_data+4,"%lf,%lf",&trif,&triv);
		  if(triv>0&&triv<=3.3)
		  {
			TIM6_Init(trif*100000.0);
			tri_Generation(triv/3.3);
		  
			WaveStart(tri);
			freShow(trif,tri);
			ampShow(triv,tri);
			select(tri);
		  }	  
	  } 
	  else if(Rx_data[0]=='s'&& Rx_data[1]=='q'&&Rx_data[2]=='u'&&Rx_data[3]=='2')
	  {
		  sscanf((char*)Rx_data+5,"%lf,%lf",&squf2,&squr);
		  
		  if(squr>0&&squr<100)
		  {
			  __HAL_TIM_SetAutoreload(&htim1,10000000/(squf2*1000)-1);
			  __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,10000000*squr/(squf2*1000*100));
			  
			  	freShow(squf2,squ2);
				ampShow(squr,squ2);
		  }		  
	  }
    }
    delay_ms(5);
}
