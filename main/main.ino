/*
 * BetriebsSoftware für die LED-Lichtbänder im Vereinsheim des Spielmannszug Büch e.V.
 * Verbaut ist derzeit ein Arduino Mega 2560, so wie zwei Strips á 420 Leds
 */

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

void animation_rot_weiss() {

  //Einblenden von Rot und Weiß, Pixel für Pixel
  for (int i = 0; i < 207; i++) {
    // Setze die LED auf Rot
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  for (int i = 207; i < 414; i++) {
    // Setze die LED auf Weiß
    leds[i] = CRGB( 108, 108, 60);
    FastLED.show();
  }
  for (int i = 414; i < 621; i++) {
    // Setze die LED auf Weiß
    leds[i] = CRGB( 108, 108, 60);
    FastLED.show();
  }
  for (int i = 621; i < 840; i++) {
    // Setze die LED auf Rot
    leds[i] = CRGB::Red;
    FastLED.show();
  }
}

void warm_weiss() {

  //Einblenden von Warm Weiß, Pixel für Pixel, in rückwärtiger Richtung
  for (int i = 840; i >= 0; i--) {
    // Setze die LED auf Warm Weiß
    leds[i] = CRGB( 70, 50, 15);
    FastLED.show();
  }
}

void loop() {
  //Zeige Animation Rot-Weiß für 10 Sekunden
  animation_rot_weiss();
  delay(10000);
  //Zeige Warm Weiß für 10 Minuten
  warm_weiss();
  delay(600000);

}
