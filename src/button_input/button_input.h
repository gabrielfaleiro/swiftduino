
#ifndef BUTTON_INPUT_H_
#define BUTTON_INPUT_H_

#include <Arduino.h>
#include <EEPROM.h>

class ButtonInput{
public:
  // Constructor
  ButtonInput(uint8_t pin, bool push_logic_level);

  uint8_t getPushType();

private:
  uint8_t _pin;
  bool _push_logic_level;
  uint16_t _short_push_millis;
  uint16_t _medium_push_millis;
  uint16_t _long_push_millis;

  unsigned long _millis_counter;
  uint8_t _prev_pin_state;

  uint8_t _readPin();
  unsigned long _getPushTime(uint8_t current_pin_state);
  unsigned long _elapsedTime(unsigned long prev, unsigned long post);
};

#endif // BUTTON_INPUT_H_