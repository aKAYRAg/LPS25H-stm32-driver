/*
 * LPS25H.c
 *
 *  Created on: 4 Ara 2022
 *      Author: kayra
 */
#include "LPS25H.h"

int LPS25H_test(void){
	HAL_StatusTypeDef status1;

	status1 = HAL_I2C_IsDeviceReady(&hi2c1, (0x5D)<<1, 4, 300);
	if(HAL_OK == status1){
		return 1;
	}
	else{
		return 0;
	}
}



int LPS25H_testID(void){

	uint8_t buffer[1];
	HAL_I2C_Mem_Read(&hi2c1, (0x5D)<<1, 0x0F, 1, buffer, 1, 300);

	if((uint8_t)0xBD == buffer[0]){
		return 1;
	}
	else {
		return 0;
	}
}



float LPS25H_read_tempdata(void){

	int16_t raw_temp;
	uint8_t TEMP_OUT_L=0, TEMP_OUT_H=0 ;




	  // l
	HAL_I2C_Mem_Read	(	&hi2c1,
							(0x5D)<<1,
							0x2B,//(2Bh)
							1,
							&TEMP_OUT_L,
							1,
							100
							);

	  // h
	HAL_I2C_Mem_Read	(	&hi2c1,
							(0x5D)<<1,
							0x2C,//(2Ch)
							1,
							&TEMP_OUT_H,
							1,
							100
							);




	raw_temp = (TEMP_OUT_H << 8) | TEMP_OUT_L;


	raw_temp = ((float)raw_temp/480.00) + 42.50;

	return (float)raw_temp;

}



float LPS25H_read_pressuredata(void){


	int32_t raw_press;
	uint8_t PRESS_OUT_XL ,PRESS_OUT_L,PRESS_OUT_H;

	// pressure read

// xl
HAL_I2C_Mem_Read	(	&hi2c1,
						(0x5D)<<1,
						0X28,//(28h)
						1,
						&PRESS_OUT_XL,
						1,
						100
						);


// l
HAL_I2C_Mem_Read	(	&hi2c1,
						(0x5D)<<1,
						0x29,//(29h)
						1,
						&PRESS_OUT_L,
						1,
						100
						);

// h
HAL_I2C_Mem_Read	(	&hi2c1,
						(0x5D)<<1,
						0x2A,//(2Ah)
						1,
						&PRESS_OUT_H,
						1,
						100
						);

	raw_press = (PRESS_OUT_H << 16) | (PRESS_OUT_L << 8) | PRESS_OUT_XL ;

	raw_press =(float)raw_press / 4096.00;

	return (float)raw_press;

}
