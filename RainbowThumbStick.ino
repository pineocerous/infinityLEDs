#include "FastLED.h"

#define LED_TYPE       WS2812
#define COLOR_ORDER     GRB      //Strip
#define NUM_LEDS        100

#define DATA_PIN    6         //Pin Out

#define LY_PIN      A0      //Pins In
#define LX_PIN      A1
#define RY_PIN      A2
#define RX_PIN      A3


#define FPS           120

#define MIN_BRIGHT    0        //Visuals
#define MAX_BRIGHT    255

CRGB leds[NUM_LEDS];

int state;


void setup() {
delay(3000);
FastLED.clear();
FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}


uint8_t gHue = 0;
int mappedGlit = 1;
  
void loop(){
  
int mappedGlit = map(analogRead(LY_PIN), 0, 1023, 0, 255);                       //Left Stick
int mappedNum = map(analogRead(LX_PIN), 0, 1023, 0, 100);
int mappedValue = map(analogRead(RY_PIN), 0, 1023, 0, 255);                     //Right Stick
EVERY_N_MILLISECONDS(1) {gHue = map(analogRead(RX_PIN), 0, 1023, 0, 255);}
  
  fill_rainbow ( leds, mappedNum, gHue, mappedGlit);                          //Display
  FastLED.show();  
  FastLED.delay(1000/FPS); 
  FastLED.setBrightness(constrain(mappedValue, MIN_BRIGHT, MAX_BRIGHT));    
  FastLED.clear();
}

