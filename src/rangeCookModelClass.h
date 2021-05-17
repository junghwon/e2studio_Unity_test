#ifndef RANGE_COOK_MODEL_CLASS_H
#define RANGE_COOK_MODEL_CLASS_H

#include "rangeCookModel.h"
//#include "rangeMagnetronModelClass.h"

struct _rangeCookModel {
    state_t state;
    int cookTimer;

    funcCookManager pCookManager;
    funcCookStart pCookStart;
    funcGetCookTimer pGetCookTimer;

//    rangeMagnetronModel_t rangeMagnetronModel;
};

#ifdef UNIT_TEST
	#define STATIC
	state_t cookManager (
		rangeCookModel_t *this,
		watt_t watt,
		int timer,
		funcStop callback,
		rangeController_t *rangeController);
	void cookStart (rangeCookModel_t *this, watt_t watt, int timer);
	int getCookTimer (rangeCookModel_t *this);
#else
	#define STATIC static
#endif // UNIT_TEST

void rangeCookModel_Constructor (rangeCookModel_t *this);

#endif // RANGE_COOK_MODEL_CLASS_H
