/*
 * sensor.c
 *
 *  Created on: 15 Oct 2015
 *      Author: simonkenny
 */

#include "si114x_algorithm.h"
#include "si114x_functions.h"
#include "si1147_i2c.h"
#include "sensor.h"

#define SI1147_DEVICE_ID      0x47

static si114x_i2c_t si114x_i2c;
static si114x_i2c_t *si114x_handle = &si114x_i2c;

int Si1147_Detect_Device__SensorCopy(I2C_TypeDef *i2c, uint8_t addr)
{
  uint8_t data;
  si114x_handle->addr = addr;
  si114x_handle->i2c  = i2c;
  data                = Si114xReadFromRegister(si114x_handle, 0);

  if (data == SI1147_DEVICE_ID)
  {
    return 1;
  }
  return 0;
}

int Si1147_MeasureIRAndVisLight(I2C_TypeDef *i2c, uint8_t addr, uint16_t *irVal, uint16_t *visVal)
{
	si114x_handle->addr = addr;
	si114x_handle->i2c  = i2c;

	// read infrared data
	*irVal  = Si114xReadFromRegister(si114x_handle, REG_ALS_IR_DATA0);
	*irVal |= Si114xReadFromRegister(si114x_handle, REG_ALS_IR_DATA1) << 8;
	// read infrared data
	*visVal  = Si114xReadFromRegister(si114x_handle, REG_ALS_VIS_DATA0);
	*visVal |= Si114xReadFromRegister(si114x_handle, REG_ALS_VIS_DATA1) << 8;

	//clear irq
	Si114xWriteToRegister(si114x_handle, REG_IRQ_STATUS, 0xff);

	return 0;
}
