/*
 * LPS25H.h
 *
 *  Created on: 4 Ara 2022
 *      Author: kayra
 */

#ifndef INC_LPS25H_H_
#define INC_LPS25H_H_

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

int LPS25H_test(void);
int LPS25H_testID(void);

float LPS25H_read_tempdata(void);
float LPS25H_read_pressuredata(void);






#endif /* INC_LPS25H_H_ */
