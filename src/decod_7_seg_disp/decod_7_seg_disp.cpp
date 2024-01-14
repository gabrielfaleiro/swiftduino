
#include "decod_7_seg_disp.h"

// Constructor implementation
Decod7SegDisp::Decod7SegDisp(int pin_a, int pin_b, int pin_c, int pin_d) {
  _pin_a = pin_a;
  _pin_b = pin_b;
  _pin_c = pin_c;
  _pin_d = pin_d;

  pinMode(_pin_a, OUTPUT);
  pinMode(_pin_b, OUTPUT);
  pinMode(_pin_c, OUTPUT);
  pinMode(_pin_d, OUTPUT);
}

void Decod7SegDisp::displayDigit(uint val) {
  digitalWrite(_pin_a, val & 0b0001);
  digitalWrite(_pin_b, val & 0b0010);
  digitalWrite(_pin_c, val & 0b0100);
  digitalWrite(_pin_d, val & 0b1000);
  return;
}