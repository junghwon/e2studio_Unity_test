/*
 * LedDriver.c
 *
 *  Created on: 2021/05/17
 *      Author: 030988
 */
#include <stdio.h>
#include <stdlib.h>
#include "LedDriver.h"

static uint16_t *ledsAddress;

void LedDriver_Create (uint16_t *ledAddr)
{
	ledsAddress = ledAddr;
	*ledsAddress = 0;
}

static uint16_t convertLedNumberToBit (int ledNumber)
{
	return (1 << (ledNumber - 1));
}

void LedDriver_TurnOn (uint16_t ledNumber)
{
	*ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff (uint16_t ledNumber)
{
	*ledsAddress = 0;
}
