
#include "timing.h"

unsigned long elapsedTime(unsigned long prev, unsigned long post){
  unsigned long max_val = 4294967295;
  unsigned long elapsed_time = 0;
  if(post > prev) elapsed_time = post - prev;
  // calculate overflow
  else elapsed_time = max_val - prev + post;
  return elapsed_time;
}