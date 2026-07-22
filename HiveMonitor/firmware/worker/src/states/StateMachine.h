#pragma once

#include "../processing/NoiseFilter.h"

class StateMachine
{
public:
    bool update(SoundLevel level);

    SoundLevel current() const;

private:
    SoundLevel currentLevel = SOUND_LOW;
};
