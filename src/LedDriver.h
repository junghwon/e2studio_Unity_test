#ifndef LED_DRIVER
#define LED_DRIVER

void LedDriver_Create (uint16_t *ledAddr);
void LedDriver_TurnOn (uint16_t ledNumber);
void LedDriver_TurnOff (uint16_t ledNumber);


#endif // LED_DRIVER
