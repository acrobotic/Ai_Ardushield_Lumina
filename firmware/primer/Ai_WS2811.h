#include <Arduino.h>
#include <util/delay.h>

// Assume Arduino Uno, digital pin 8 (ie. port B, pin 0)

#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_PIN PINB
#define LED_BIT _BV(0)
#define NOP __asm__("nop\n\t")

/*------------------------------------------------------------------------
  Set the LED pin as output on startup
------------------------------------------------------------------------*/
class Ai_WS2811 {
  
  public:
    byte _r, _g, _b;
    void init(uint8_t);
    void send();
    void sendByte(byte);
    void setColor(byte, byte, byte);
};
