#ifndef __BACKGROUND_H
#define	__BACKGROUND_H

#include "OLED_I2C.h"

void BackGround_Init(void);
void freShow(double number,int wave);
void ampShow(double number,int wave);
void fre_ampShow(void);
void select(int wave);
#endif
