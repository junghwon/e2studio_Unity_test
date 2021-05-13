#ifndef RANGE_CONTROLLER_CLASS_H
#define RANGE_CONTROLLER_CLASS_H

#include "rangeController.h"
#include "rangeCookModelClass.h"

struct _rangeController {
    watt_t watt;
    int timer;

    funcStart pStart;
    funcStop pStop;

    rangeCookModel_t rangeCookModel;
};

#ifdef UNIT_TEST
#define STATIC
void rangeControllerStart (rangeController_t *this);
void rangeControllerStop (rangeController_t *this);
#else
#define STATIC static
#endif // UNIT_TEST

void RangeController_Constructor (rangeController_t *this);

#endif // RANGE_CONTROLLER_CLASS_H
