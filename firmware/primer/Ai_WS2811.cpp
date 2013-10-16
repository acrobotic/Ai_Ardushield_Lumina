#include "Ai_WS2811.h"

void Ai_WS2811::init(uint8_t pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void Ai_WS2811::send() {
  sendByte(_r);
  sendByte(_g);
  sendByte(_b);
}  


void Ai_WS2811::setColor(byte r, byte g, byte b) {
  _r = r;
  _g = g;
  _b = b;
} 

void Ai_WS2811::sendByte(byte b) {
  byte i=8;
  do {
    if ((b&0x80)==0) {
      // Send a '0'
      if (F_CPU==16000000L) {
        LED_PIN=LED_BIT;NOP;// Hi (start)
        NOP;NOP;            // Hi
        LED_PIN=LED_BIT;NOP;// Lo (250ns)
        NOP;NOP;            // Lo
        NOP;NOP;            // Lo (500ns)
      }
      else if (F_CPU==8000000L) {
        LED_PIN = LED_BIT;  // Hi (start)
        NOP;                // Hi
        LED_PIN = LED_BIT;  // Lo (250ns)
        NOP;                // Lo
        NOP;                // Lo (500ns)
        NOP;                // Lo (data bit here!)  
        NOP;                // Lo (750ns)
      }
    }
    else {
      // Send a '1'
      if (F_CPU==16000000L) {
        LED_PIN=LED_BIT;NOP;// Hi (start)
        NOP;NOP;            // Hi
        NOP;NOP;            // Hi (250ns)
        NOP;NOP;            // Hi
        NOP;NOP;            // Hi (500ns)
        LED_PIN=LED_BIT;    // Lo (625ns)
      }
      else if (F_CPU==8000000L) {
        LED_PIN = LED_BIT;  // Hi (start)
        NOP;                // Hi
        NOP;                // Hi (250ns)
        NOP;                // Hi
        NOP;                // Hi (500ns)
        NOP;                // Hi (data bit here!)
        LED_PIN = LED_BIT;  // Lo (750ns)
      }
    }
    b = b+b;
  } while (--i!=0);
}
