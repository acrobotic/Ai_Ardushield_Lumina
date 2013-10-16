#include "Ai_WS2811.h"

#define NUM_PIXELS 3
#define DATA_PIN 8

Ai_WS2811 ws2811;

struct CRGB {
  unsigned char g;
  unsigned char r;
  unsigned char b;
} *leds;

//some initial values
void setup()
{
  ws2811.init(DATA_PIN,NUM_PIXELS);
  leds = (struct CRGB*)ws2811.getRGBData();
}

void loop(){
  rainbow();
}

/**
 * Color climb function
 **/
void rainbow(){
  while(1) {
    for(int i = 255; i >= 0; i--)
    {
      int val = i;
      for (int led = 0; led < 3; led++) {
          val = (val + 12) % 255;
          setHue(val, led);
      }
      ws2811.sendLedData();
      delay(100);
    }
  }
}

/**
 * HVS to RGB comversion (simplified to the range 0-255)
 **/
void setHue(int h, uint8_t n) {
  //this is the algorithm to convert from RGB to HSV
  double r=0; 
  double g=0; 
  double b=0;

  double hf=h/42.5; // Not /60 as range is _not_ 0-360

  int i=(int)floor(h/42.5);
  double f = h/42.5 - i;
  double qv = 1 - f;
  double tv = f;

  switch (i)
  {
  case 0: 
    r = 1;
    g = tv;
    break;
  case 1: 
    r = qv;
    g = 1;
    break;
  case 2: 
    g = 1;
    b = tv;
    break;
  case 3: 
    g = qv;
    b = 1;
    break;
  case 4:
    r = tv;
    b = 1;
    break;
  case 5: 
    r = 1;
    b = qv;
    break;
  }

  leds[n].r = constrain((int)255*r,0,255);
  leds[n].g = constrain((int)255*g,0,255);
  leds[n].b = constrain((int)255*b,0,255);
}
