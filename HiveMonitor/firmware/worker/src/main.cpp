#include "config/Config.h"
#include "config/Pins.h"
#include "sensors/Microphone.h"


void setup() {
	// leds
	pinMode(PURPLE_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);

	// buzzer
	pinMode(BUZZER_PIN, OUTPUT);
}


void loop() {
	
}
