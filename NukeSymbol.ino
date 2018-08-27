#include "FastLED.h"
#define DATA_PIN    6
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    51
#define BRIGHTNESS         125
#define FRAMES_PER_SECOND  60

#define CK1 (0,4)
#define CK2 (5,13)
#define CK3 (14,21)
#define CK4 (22,30)
#define CK5 (31,39)
#define CK6 (40,48)

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}
  
void loop() 
{  FastLED.show();  
fill_solid( leds, CK6, CRGB::Yellow);
fill_solid( leds, CK5, CRGB::Black);
fill_solid( leds, CK4, CRGB::Yellow);
fill_solid( leds, CK3, CRGB::Black); 
fill_solid( leds, CK2, CRGB::Yellow);
fill_solid( leds, CK1, CRGB::Black);

  }

