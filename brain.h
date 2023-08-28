#ifndef __BRAIN_HEADER__
#define __BRAIN_HEADER__

#include <random>
#include <iostream>

class GameBrain
{
  int answer;
  int prev_guess;

public:
  GameBrain(int maxint);
  int make_guess(int guess);
  void begin();
};

enum status
{
  hot,
  cold,
  right,
  start
};

#endif