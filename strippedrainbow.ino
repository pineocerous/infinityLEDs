#include "FastLED.h"
#define DATA_PIN    6
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    51
#define BRIGHTNESS         60
#define FRAMES_PER_SECOND  60
CRGB leds[NUM_LEDS];


int gHue=0;


void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop (){
  FastLED.show();
  fill_gradient (leds, uint16_t 51, CRGB::Red, CRGB::Blue);
 ;
}

