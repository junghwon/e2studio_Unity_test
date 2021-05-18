/*
 * portIn.c
 *
 *  Created on: 2021/05/18
 *      Author: kehnc
 */
#include "portIn.h"

// この関数を割込み処理から呼ぶ
// ↓のように
// portIn_Interrupt (&portBack);
void portIn_Interrupt (portIn_t *this)
{
	if (this->activeCount < this->debounce) {
		this->activeCount++;
	} else {
		this->activeCount = 0;
		this->isActive = 1;
	}
}

void portIn_Constructor (portIn_t *this)
{
	this->debounce = 0;
	this->activeCount = 0;
	this->isActive = 0;
}
