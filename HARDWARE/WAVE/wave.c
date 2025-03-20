#include "tim.h"
#include "dac.h"
#include "dma.h"
#include "WAVE.h"

#define 	PI  		3.1415926
#define 	tableSize 	500

uint16_t squTable[tableSize];
uint16_t triTable[tableSize];
uint16_t sinTable[tableSize];

void squ_Generation(double r)
{
	uint32_t i;
	for(i=0;i<tableSize/2;i++)
	{
		squTable[i]=50;
	}
	for(i=tableSize/2;i<tableSize;i++)
	{
		squTable[i]=4095*r;
	}
}

void sin_Generation(double r)
{
	uint32_t i;
	for(i=0;i<tableSize;i++)
	{
		sinTable[i] = (sin(2.0*PI*i/tableSize)+1)*2047.0*r;	
	}	
}

void tri_Generation(double r)
{
	uint32_t i;
	for(i=0;i<tableSize/2;i++)
	{
		triTable[i]=(2*4095*i/tableSize)*r;
	}
	for(i=tableSize/2;i<tableSize;i++)
	{
		triTable[i]=(2*4095*(tableSize-i)/tableSize)*r;
	}
}


void WaveStart(int wave)
{
	switch (wave)
	{
		case sine :   HAL_TIM_Base_Start(&htim6);
					  HAL_DAC_Start_DMA(&hdac4,DAC_CHANNEL_1,(uint32_t *)sinTable,tableSize,DAC_ALIGN_12B_R);
					  break;
		
		case squ1 :   HAL_TIM_Base_Start(&htim6);
					  HAL_DAC_Start_DMA(&hdac4,DAC_CHANNEL_1,(uint32_t *)squTable,tableSize,DAC_ALIGN_12B_R);
					  break;
		
		case tri :    HAL_TIM_Base_Start(&htim6);
					  HAL_DAC_Start_DMA(&hdac4,DAC_CHANNEL_1,(uint32_t *)triTable,tableSize,DAC_ALIGN_12B_R); 
					  break;
		
		default :	  HAL_TIM_Base_Stop(&htim6);
					  HAL_DAC_Stop_DMA(&hdac4,DAC_CHANNEL_1);
					  break;
	}
}
