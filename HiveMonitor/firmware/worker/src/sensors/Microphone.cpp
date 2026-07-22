#include <Arduino.h>

enum SoundLevel : uint8_t {
    SOUND_LOW = 0,
    SOUND_MID,
    SOUND_HIGH,
    SOUND_VERY_HIGH,
    SOUND_COUNT
};

constexpr int leds[SOUND_COUNT] = {
    GREEN_LED,
    YELLOW_LED,
    RED_LED,
    PURPLE_LED
};

static_assert(sizeof(leds) / sizeof(leds[0]) == SOUND_COUNT,
    "O número de LEDs não bate com SOUND_COUNT!");

constexpr int HYSTERESIS = 15; // Margem para evitar flicker nas bordas

void listener() {
    static SoundLevel lastLevel = SOUND_LOW;
    int value = analogRead(MIC_PIN);

    SoundLevel currentLevel = lastLevel;

    // Aplicação da histerese baseada no estado anterior
    switch (lastLevel) {
    case SOUND_LOW:
        if (value > 620 + HYSTERESIS) currentLevel = SOUND_MID;
        break;

    case SOUND_MID:
        if (value < 620 - HYSTERESIS) currentLevel = SOUND_LOW;
        else if (value > 720 + HYSTERESIS) currentLevel = SOUND_HIGH;
        break;

    case SOUND_HIGH:
        if (value < 720 - HYSTERESIS) currentLevel = SOUND_MID;
        else if (value > 850 + HYSTERESIS) currentLevel = SOUND_VERY_HIGH;
        break;

    case SOUND_VERY_HIGH:
        if (value < 850 - HYSTERESIS) currentLevel = SOUND_HIGH;
        break;

    default:
        currentLevel = SOUND_LOW;
        break;
    }

    // Só atua na GPIO se houver mudança real de estado
    if (currentLevel != lastLevel) {
        digitalWrite(leds[lastLevel], LOW);
        digitalWrite(leds[currentLevel], HIGH);
        lastLevel = currentLevel;
    }
}
