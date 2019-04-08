#include <FastLED.h>

#define NUM_STRIPS 2  //Anzahl der Strips
#define NUM_LEDS_PER_STRIP 420 //Anzahl der LEDS im Strip
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS //NUM_LEDS = LEDS per Strip * Anzahl der Strips
#define BRIGHTNESS 96 //Definition der Gesamthelligkeit

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];


void setup() {
  
  delay(3000); // Warten, damit der Strip nicht flackert.
  
  // 420 LEDS an Pin 3, beginnend bei index 0
  FastLED.addLeds<NEOPIXEL, 3>(leds, 0, NUM_LEDS_PER_STRIP);

  // 420 LEDS an Pin 5, beginnend bei index 420
  FastLED.addLeds<NEOPIXEL, 5>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  
  //Setze die Gesamthelligkeit
  FastLED.setBrightness( BRIGHTNESS );

}

void loop() {

  for (int i = 0; i < 207; i++) {
    // set our current dot to red
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  for (int i = 207; i < 414; i++) {
    // set our current dot to red
    leds[i] = CRGB( 108, 108, 60);
    FastLED.show();
  }
  for (int i = 414; i < 621; i++) {
    // set our current dot to red
    leds[i] = CRGB( 108, 108, 60);
    FastLED.show();
  }
  for (int i = 621; i < 840; i++) {
    // set our current dot to red
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  delay(10000);
  for (int i = 840; i >= 0; i--) {
    leds[i] = CRGB( 70, 50, 15);
    FastLED.show();
  }

  delay(600000);

}
