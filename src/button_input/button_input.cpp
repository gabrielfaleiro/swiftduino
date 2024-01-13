
// REF:
// https://blog.hirnschall.net/esp8266-eeprom/

#include <Arduino.h>
#include "button_input.h"
// Constructor
ButtonInput::ButtonInput(uint8_t pin, bool push_logic_level){
  _push_logic_level = push_logic_level;
  _pin = pin;
  pinMode(_pin, INPUT);

  _short_push_millis    =   200;
  _medium_push_millis   =  3000;
  _long_push_millis     = 10000;

  _millis_counter = 0;
  _prev_pin_state = ! push_logic_level;
}

uint8_t ButtonInput::getPushType(){
  unsigned long running_millis = 0;
  uint8_t push_type = 0;

  running_millis = _getPushTime(_readPin());

  if(running_millis >= _long_push_millis) push_type = 3; // long
  else{
    if(running_millis >= _medium_push_millis) push_type = 2; // medium
    else{
      if(running_millis >= _short_push_millis) push_type = 1; // short
      else{
        push_type = 0; // not detected
      }
    }
  }

  return push_type;
}

uint8_t ButtonInput::_readPin(){
  uint8_t current_pin_state = 0;
  

  current_pin_state = digitalRead(_pin);
  // Negate read pin state if inverse logic
  if(!_push_logic_level) current_pin_state = ! current_pin_state;

  return current_pin_state;
}

unsigned long ButtonInput::_getPushTime(uint8_t current_pin_state){
  unsigned long elapsed_time = 0;

  // Evaluate pin state transition
  if(_prev_pin_state != current_pin_state){
    if(current_pin_state && ! _prev_pin_state){ // Rised state
      _millis_counter = millis();
    }
    else{ // Lowered state
      // Send calculated value
      elapsed_time = _elapsedTime(_millis_counter, millis());
    }

    _prev_pin_state = current_pin_state;
  }

  return elapsed_time;
}

unsigned long ButtonInput::_elapsedTime(unsigned long prev, unsigned long post){
  unsigned long max_val = 4294967295;
  unsigned long elapsed_time = 0;
  if(post > prev) elapsed_time = post - prev;
  // calculate overflow
  else elapsed_time = max_val - prev + post;
  return elapsed_time;
}

