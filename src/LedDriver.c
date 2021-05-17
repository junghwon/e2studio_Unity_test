/*
 * LedDriver.c
 *
 *  Created on: 2021/05/17
 *      Author: 030988
 */
#ifdef UNIT_TEST

#include <stdio.h>
#include <stdlib.h>
#include "LedDriver.h"

static uint16_t *ledsAddress;

void LedDriver_Create (uint16_t *ledAddr)
{
	ledsAddress = ledAddr;
	*ledsAddress = 0;
}

void LedDriver_TurnOn (uint16_t ledNumber)
{
	*ledsAddress = 1;
}

void LedDriver_TurnOff (uint16_t ledNumber)
{
	*ledsAddress = 0;
}

#endif // UNIT_TEST
