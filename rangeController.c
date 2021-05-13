#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rangeControllerClass.h"

STATIC void rangeControllerStart (rangeController_t *this);
STATIC void rangeControllerStop (rangeController_t *this);

const rangeController_t rangeControllerInitValue = {
    watt_500,
    0,
    &rangeControllerStart,
    &rangeControllerStop,
};


STATIC void rangeControllerStart (rangeController_t *this)
{
//    if (this->rangeKeyController.pGetKey (&this->rangeKeyController, 's')) {
        this->rangeCookModel.pCookStart (&this->rangeCookModel, this->watt, this->timer);
//    }
}

STATIC void rangeControllerStop (rangeController_t *this)
{
#ifdef UNIT_TEST
    printf ("rangeControllerStop() is called\n");
#endif // UNIT_TEST
    this->watt = rangeControllerInitValue.watt;
    this->timer = rangeControllerInitValue.timer;
}


void RangeController_Constructor (rangeController_t *this)
{
    this->watt = rangeControllerInitValue.watt;
    this->timer = rangeControllerInitValue.timer;

    this->pStart = rangeControllerInitValue.pStart;
    this->pStop = rangeControllerInitValue.pStop;

    rangeCookModel_Constructor (&this->rangeCookModel);
}
