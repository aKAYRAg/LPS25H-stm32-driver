/*
 * LPS25H.h
 *
 *  Created on: 22 Ara 2022
 *      Author: kayra
 */

#include "stm32f4xx_hal.h"
#include "stdint.h"
#include <math.h>

#ifndef INC_LPS25H_H_
#define INC_LPS25H_H_

extern I2C_HandleTypeDef hi2c1;

void LPS25H_init(void);

float read_data_temp(void);
float read_data_pressure(void);

#endif /* INC_LPS25H_H_ */
