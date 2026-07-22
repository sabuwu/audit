#pragma once

#include <Arduino.h>

enum SoundLevel : uint8_t
{
    SOUND_LOW,
    SOUND_MID,
    SOUND_HIGH,
    SOUND_VERY_HIGH
};

class NoiseFilter
{
public:
    SoundLevel update(int sample);

private:
    SoundLevel classify(int sample);
};
