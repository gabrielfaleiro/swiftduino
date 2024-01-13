
#ifndef DECOD_7SEG_DISP_H_
#define DECOD_7SEG_DISP_H_

#include <Arduino.h>

class Decod7SegDisp{
public:
    // Constructor
    Decod7SegDisp(int pin_a, int pin_b, int pin_c, int pin_d);

    // Public method to read inputs
    void displayDigit(uint val);

private:
    // Member variables for input pins
    int _pin_a;
    int _pin_b;
    int _pin_c;
    int _pin_d;
};

#endif // DECOD_7SEG_DISP_H_