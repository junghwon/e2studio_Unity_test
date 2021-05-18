/*
 * portIn.h
 *
 *  Created on: 2021/05/18
 *      Author: kehnc
 */

#ifndef PORTIN_H_
#define PORTIN_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	uint8_t debounce;
	uint8_t activeCount;
	uint8_t isActive;
} portIn_t;

void portIn_Interrupt (portIn_t *this);
void portIn_Constructor (portIn_t *this);

#endif /* PORTIN_H_ */
