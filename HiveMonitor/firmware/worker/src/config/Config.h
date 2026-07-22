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
constexpr uint32_t SILENCE_TIMEOUT_MS = 120000; // 2 min (120.000 ms)
constexpr uint32_t OBS_MS = 300000;             // 5 min (300.000 ms)


//	=== daily limites ===
constexpr uint8_t MAX_PURPLES_EVENTS = 3;
