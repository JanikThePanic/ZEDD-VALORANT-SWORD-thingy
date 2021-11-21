#include <Arduino.h>
#include "FastLED.h"

// static varibles

// led strip data pin
#define LED_DT 7
// color order, GRB for WS2812B and GBR for APA102
#define COLOR_ORDER GRB
//led chipset
#define LED_TYPE WS2812
//number of leds
#define NUM_LEDS 5

// Initialize changeable global variables.

// Overall brightness definition. It can be changed on the fly.
uint8_t max_bright = 255;
// Initialize our LED array.
struct CRGB leds[NUM_LEDS];
// speed
int speed = 10;
//delta hue
int deltaHue = 10;

void setup()
{
	LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setBrightness(max_bright);
}

void loop()
{
	// rainbow wave
	uint8_t thisHue = beatsin8(speed, 0, 255);

	// FastLED's fill_rainbow routine.
	fill_rainbow(leds, NUM_LEDS, thisHue, deltaHue);

	FastLED.show();
}