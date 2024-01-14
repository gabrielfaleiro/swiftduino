
/*
I wanted to create a static state machine for some reasons:
- I don't want dinamically created objects that can lead to errors during runtime
- I want to hide the application logic from the main (setup and loop) code

The consulted libraries are:
- https://github.com/jrullan/StateMachine?tab=readme-ov-file
- https://github.com/luisllamasbinaburo/Arduino-StateMachine/blob/master/src/StateMachineLib.cpp
- https://github.com/luisllamasbinaburo/Arduino-StateMachine/tree/master

*/

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

// Include the following library to make code more modular
// #include "application_logic.h"

struct InputSignals;
struct StateSignals;
struct OutputSignals;

enum States;

class State{
public:
  // Constructor
  State(_compute, _inTransition, _outTransition);

  void compute(InputSignals);
  void inTransition(InputSignals);
  void outTransition(InputSignals);

private:
  void (*_compute)(InputSignals, StateSignals, OutputSignals);
  void (*_inTransition)(InputSignals, StateSignals, OutputSignals);
  void (*_outTransition)(InputSignals, StateSignals, OutputSignals);

  static InputSignals input;
  static StateSignals state;
  static OutputSignals output;
};

class StateMachine{
public:
  StateMachine();

private:


};

#endif // STATE_MACHINE_H_