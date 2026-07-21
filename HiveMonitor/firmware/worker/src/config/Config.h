#pragma once


//	=== mic. ===
constexpr int MIC_PIN = A0;

constexpr uint16_t SAMPLE_WINDOW_MS = 50;
constexpr float EMA_ALPHA = 0.10f;


//	=== thresholds ===
constexpr uint16_t THRESHOLD_NORMAL = 50;
constexpr uint16_t THRESHOLD_WARNING = 150;
constexpr uint16_t THRESHOLD_HIGH = 350;


//	=== timers ===
constexpr uint16_t SILENCE_TIMEOUT_MS = 1200000; // 2 min.
constexpr uint16_t OBS_MS = 300000; // 5 min.


//	=== daily limites ===
constexpr uint8_t MAX_PURPLES_EVENTS = 3;
