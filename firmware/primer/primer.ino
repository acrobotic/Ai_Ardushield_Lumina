/*------------------------------------------------------------------------
  WS2811 demo
------------------------------------------------------------------------*/
#include "Ai_WS2811.h"

#define DATA_PIN 8
#define NUM_LEDS 1

Ai_WS2811 ws2811;

void sendLEDs()
{
  cli();
  for (byte i=0; i<NUM_LEDS; ++i) {
    ws2811.send();
  }
  sei();
}

void setup()
{
  ws2811.init(DATA_PIN);
}

byte a = 0x00;
byte b = 0xff;

void loop()
{
  // Toggles LED between Blue, Green, Read
  ws2811.setColor(a,a,b);
  sendLEDs();
  _delay_ms(1000);
  
  ws2811.setColor(a,b,a);
  sendLEDs();
  _delay_ms(1000);
  
  ws2811.setColor(b,a,a);
  sendLEDs();
  _delay_ms(1000);
}

