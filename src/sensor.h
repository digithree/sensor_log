/*
 * sensor.h
 *
 *  Created on: 15 Oct 2015
 *      Author: simonkenny
 */

#ifndef SENSOR_H_
#define SENSOR_H_

int Si1147_MeasureIRAndVisLight(I2C_TypeDef *i2c, uint8_t addr, uint16_t *irVal, uint16_t *visVal);
int Si1147_Detect_Device__SensorCopy(I2C_TypeDef *i2c, uint8_t addr);

#endif /* SENSOR_H_ */
