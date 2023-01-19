/*
 * LPS25H.c
 *
 *  Created on: 22 Ara 2022
 *      Author: kayra
 */

#include "LPS25H.h"

void LPS25H_init(void){

	uint8_t data;

	// PD = 1 (active mode);  ODR = 011 (12.5 Hz pressure & temperature output data rate)
	data = 0xB0; // 0xB0 = 0b10110000
	HAL_I2C_Mem_Write	(			&hi2c1,
							(0x6B)<<1,
							0x20,// CTRL_REG1 (20h)
							1,
							&data,
							1,
							HAL_MAX_DELAY
						 );


}


float read_data_temp(void){

	int16_t raw_temp;
	uint8_t TEMP_OUT_L=0, TEMP_OUT_H=0 ;

	  // l
	HAL_I2C_Mem_Read	(			&hi2c1,
							(0x5D)<<1,
							0x2B,//(2Bh)
							1,
							&TEMP_OUT_L,
							1,
							HAL_MAX_DELAY
							);

	  // h
	HAL_I2C_Mem_Read	(			&hi2c1,
							(0x5D)<<1,
							0x2C,//(2Ch)
							1,
							&TEMP_OUT_H,
							1,
							HAL_MAX_DELAY
							);

	raw_temp = (TEMP_OUT_H << 8) | TEMP_OUT_L;

	raw_temp = ((float)raw_temp/480.00) + 42.50;

	return (float)raw_temp;

}

float read_data_pressure(void){


	int32_t raw_press;
	uint8_t PRESS_OUT_XL ,PRESS_OUT_L,PRESS_OUT_H;



// pressure read

// xl
HAL_I2C_Mem_Read	(			&hi2c1,
						(0x5D)<<1,
						0X28,//(28h)
						1,
						&PRESS_OUT_XL,
						1,
						HAL_MAX_DELAY
						);


// l
HAL_I2C_Mem_Read	(			&hi2c1,
						(0x5D)<<1,
						0x29,//(29h)
						1,
						&PRESS_OUT_L,
						1,
						HAL_MAX_DELAY
						);

// h
HAL_I2C_Mem_Read	(			&hi2c1,
						(0x5D)<<1,
						0x2A,//(2Ah)
						1,
						&PRESS_OUT_H,
						1,
						HAL_MAX_DELAY
						);

	raw_press = (PRESS_OUT_H << 16) | (PRESS_OUT_L << 8) | PRESS_OUT_XL ;

	raw_press =(float)raw_press / 4096.00;

	return (float)raw_press;

}
