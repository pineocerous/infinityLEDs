

#define buttonPin 3
#include "jsbutton.h"
#include "EEPROM.h"
#include "FastLED.h"

#define datapin 6
#define COLOR_ORDER GRB
#define LED_TYPE WS2812
#define NUM_LEDS 51
#define MaxBrightness 255
#define MinBrightness 0
#define ARRAY_SIZE(A) (sizeof(A) / sizeof ((A) [0]))


const int brightnessInPin = A0;
uint8_t maxMode = 5;
int eepaddress = 0;
uint8_t gCurrentPatternNumber = 0;
uint8_t gHue=0;

struct CRGB leds[NUM_LEDS];
typedef void (*SimplePatternList[])();

void setup() {

  delay (1000);
  LEDS.addLeds<LED_TYPE, datapin, COLOR_ORDER>(leds, NUM_LEDS);
  
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  
  gCurrentPatternNumber = EEPROM.read(eepaddress);
  if (gCurrentPatternNumber > maxMode) gCurrentPatternNumber = 0;


}

void loop() {
 int mappedValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);
  readbutton();
  FastLED.setBrightness(MaxBrightness);
  FastLED.setBrightness(constrain(mappedValue, MinBrightness, MaxBrightness));

  EVERY_N_MILLISECONDS(20) {                                  
    gHue++;
    
  }
  FastLED.show();
}

void readbutton() {   
  SimplePatternList gPatterns = {rainbow,sinelon};     
    EVERY_N_MILLISECONDS(50) {
    gPatterns[gCurrentPatternNumber]();                       
  }                                    
  uint8_t b = checkButton();
  if (b == 1) {gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);}
  if (b == 2) {gCurrentPatternNumber = 0;}
  if (b == 3) {EEPROM.write(eepaddress,gCurrentPatternNumber);
  }
}
void rainbow() {
  fill_rainbow(leds, NUM_LEDS, gHue, 7);              
  }
void sinelon() {                                          
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int pos = beatsin16(13,0,NUM_LEDS-1);
  leds[pos] += CHSV(gHue, 255, 192);
  }

