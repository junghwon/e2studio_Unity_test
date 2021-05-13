#ifndef RANGE_CONTROLLER_H
#define RANGE_CONTROLLER_H

#define TIMER_MAX (60)

typedef enum {
    watt_100 = 1,
    watt_200,
    watt_300,
    watt_400,
    watt_500,
} watt_t;

typedef struct _rangeController rangeController_t;

typedef void (*funcStart)(rangeController_t *this);
typedef void (*funcStop)(rangeController_t *this);

#endif // RANGE_CONTROLLER_H
