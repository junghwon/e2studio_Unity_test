#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "rangeCookModelClass.h"

STATIC state_t cookManager (
    rangeCookModel_t *this,
    watt_t watt,
    int timer,
    funcStop callback,
    rangeController_t *rangeController);
STATIC void cookStart (rangeCookModel_t *this, watt_t watt, int timer);
STATIC int getCookTimer (rangeCookModel_t *this);

const rangeCookModel_t rangeCookModelInitValue = {
    state_standby,
    0,
    &cookManager,
    &cookStart,
    &getCookTimer,
};

STATIC void stateStandby (rangeCookModel_t *this, watt_t watt, int timer)
{
//    this->rangeMagnetronModel.init (&this->rangeMagnetronModel);
}

STATIC void stateCook (rangeCookModel_t *this, watt_t watt, int timer)
{
//    this->rangeMagnetronModel.manager (&this->rangeMagnetronModel);

    if (this->cookTimer <= 0) {
        this->state = state_end;
    }
}

STATIC void stateEnd (
    rangeCookModel_t *this,
    funcStop callback,
    rangeController_t *rangeController)
{
    this->state = state_standby;
    callback (rangeController);
}

STATIC state_t cookManager (
    rangeCookModel_t *this,
    watt_t watt,
    int timer,
    funcStop callback,
    rangeController_t *rangeController)
{
    switch (this->state) {
        default:
        case state_standby:
            stateStandby (this, watt, timer);
        break;
        case state_cook:
            stateCook (this, watt, timer);
        break;
        case state_end:
            stateEnd (this, callback, rangeController);
        break;
    }

    return (this->state);
}

STATIC void cookStart (rangeCookModel_t *this, watt_t watt, int timer)
{
    this->state = state_cook;
    this->cookTimer = timer;
//    this->rangeMagnetronModel.mqStart (&this->rangeMagnetronModel, watt);
}

STATIC int getCookTimer (rangeCookModel_t *this)
{
    return (this->cookTimer);
}

void rangeCookModel_Constructor (rangeCookModel_t *this)
{
    this->state = rangeCookModelInitValue.state;
    this->cookTimer = rangeCookModelInitValue.cookTimer;

    this->pCookManager = rangeCookModelInitValue.pCookManager;
    this->pCookStart = rangeCookModelInitValue.pCookStart;
    this->pGetCookTimer = rangeCookModelInitValue.pGetCookTimer;

//    rangeMagnetronModel_Constructor (&this->rangeMagnetronModel);
}
