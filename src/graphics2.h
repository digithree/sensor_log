/*
 * graphics2.h
 *
 *  Created on: 8 Oct 2015
 *      Author: simonkenny
 */

#ifndef GRAPHICS2_H_
#define GRAPHICS2_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DEMO_VERSION "Demo v1.0"

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/
void GRAPHICS_Init(void);
void GRAPHICS_Sleep(void);
void GRAPHICS_Wake(void);
void GRAPHICS_ShowStatus(bool si114x_status, bool si7013_status, bool removeObject, bool lowBat);
void GRAPHICS_Draw(int logIdx, int logLen, int8_t *tData, bool lowBat, int uptimeTicks, int ticksInHr);

#ifdef __cplusplus
}
#endif


#endif /* GRAPHICS2_H_ */
