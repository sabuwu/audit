#pragma once

#include <Arduino.h>

// === LEDs ===
constexpr int PURPLE_LED = 5;  // GPIO5 (D1)
constexpr int RED_LED = 4;  // GPIO4 (D2)
constexpr int YELLOW_LED = 14; // GPIO14 (D5)
constexpr int GREEN_LED = 12; // GPIO12 (D6)

// === Hardware ===
constexpr int BUZZER_PIN = 15; // GPIO15 (D8 - Garantir PULL-DOWN no boot)
// (opt.) constexpr int MICROPHONE_PIN = 13;

// === Microfone ===
constexpr int MIC_PIN = A0;
constexpr uint16_t SAMPLE_WINDOW_MS = 50;
constexpr float EMA_ALPHA = 0.10f;

// === Limiares (ADC/Delta) ===
constexpr uint16_t THRESHOLD_NORMAL = 50;
constexpr uint16_t THRESHOLD_WARNING = 150;
constexpr uint16_t THRESHOLD_HIGH = 350;

// === Timers (Ajustado para uint32_t) ===
constexpr uint32_t SILENCE_TIMEOUT_MS = 120000; // 2 min
constexpr uint32_t OBS_MS = 300000; // 5 min

// === Limites Diários ===
constexpr uint8_t MAX_PURPLES_EVENTS = 3;
