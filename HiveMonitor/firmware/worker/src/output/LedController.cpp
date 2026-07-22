#include "LedController.h"

#include "../config/Pins.h"

constexpr int LEDS[] =
{
    GREEN_LED,
    YELLOW_LED,
    RED_LED,
    PURPLE_LED
};

void LedController::begin()
{
    for (int led : LEDS)
    {
        pinMode(led, OUTPUT);
        digitalWrite(led, LOW);
    }
}

void LedController::setLevel(SoundLevel level)
{
    for (int led : LEDS)
        digitalWrite(led, LOW);

    digitalWrite(LEDS[level], HIGH);
}
