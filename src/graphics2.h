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
int GRAPHICS_DisplayIsAwake(void);
void GRAPHICS_Draw(int displayState, int logIdx, int logLen,
		int8_t *tData, int8_t *rhData, int8_t *uvData, bool lowBat, int uptimeTicks, int ticksInHr);

#ifdef __cplusplus
}
#endif


#endif /* GRAPHICS2_H_ */
