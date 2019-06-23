/*
 * BetriebsSoftware für die LED-Lichtbänder im Vereinsheim des Spielmannszug Büch e.V.
 * Verbaut ist derzeit ein Arduino Mega 2560, so wie zwei Strips á 420 Leds
 * Autor: Edward Hamann // Christoph Galle
 * Datum: 22.05.2019
 *
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

  def_bereiche();

}

void def_bereiche() {
//Array Grün: 0-70,141-210,211-280,351-420,421-490,561-630,631-700,771-840
//Array Weiß: 71-140,281-350,491-560,701-770,
int bereiche_green[15]; //Array für die grünen Abschnitte
int bereiche_white[7]; //Array für die weißen Abschnitte

int b_green_anz = 15; //Zähler für Schleifen
int b_white_anz = 7; // ""

// Bereiche definieren
 bereiche_green[0] = 0;
 bereiche_green[1] = 70;
 bereiche_green[2] = 141;
 bereiche_green[3] = 210;
 bereiche_green[4] = 211;
 bereiche_green[5] = 280;
 bereiche_green[6] = 351;   
 bereiche_green[7] = 420;
 bereiche_green[8] = 421;
 bereiche_green[9] = 490;
 bereiche_green[10] = 561;
 bereiche_green[11] = 630;
 bereiche_green[12] = 631;
 bereiche_green[13] = 700;
 bereiche_green[14] = 771; 
 bereiche_green[15] = 840;

 bereiche_white[0] = 71;
 bereiche_white[1] = 140;
 bereiche_white[2] = 281;
 bereiche_white[3] = 350;
 bereiche_white[4] = 491;
 bereiche_white[5] = 560;
 bereiche_white[6] = 701;
 bereiche_white[7] = 770;

}

void fill_green() {

int x = 0 //zähler für Array und Schleife definieren

while (x <= b_green_anz){ //gesamtes Array durchklaufen

//setzen der LEDs im Array grün
  for (int i = bereiche_green[x]; i <= bereiche_green[x+1]; i++) {

    leds[i] = CRGB( 0, 153, 51);

  }

x=x+2; //Zähler um 2 erhöhen damit nächster Bereich durchlaufen wird

}

}

void fill_white() {

int x = 0 //zähler für Array und Schleife definieren

while (x <= b_white_anz){ //gesamtes Array durchklaufen

//setzen der LEDs im Array weiß
  for (int i = bereiche_white[x]; i <= bereiche_white[x+1]; i++) {

    leds[i] = CRGB( 108, 108, 60);

  }

x=x+2; //Zähler um 2 erhöhen damit nächster Bereich durchlaufen wird

}

}


void loop() {
  //Zeige die Farben an und bleibe in einer Schleife hängen
  def_bereiche();
  fill_white();
  fill_green();
  while (1=1){
    //never ending delay
  }

}
