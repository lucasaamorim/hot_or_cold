#include "brain.h"

/*!
 * Uses built-in methods from the STL to generate a random number in the range [1,maxint], 
 * also initializes prev_guess to placeholder value.
 * @param maxint Upper bound of closed range to generate random number.
 */
GameBrain::GameBrain(int maxint)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(1, maxint);
  this->answer = distr(gen);
  this->prev_guess = (int)1e9;
}


/*!
 * Compares a guess provided by the user with the random number stored in the class
 * @param guess Value to compare
 * @return a status code (right, hot, cold, start).
*/
int GameBrain::make_guess(int guess)
{
  if (guess == answer)
  {
    std::cout << ">>> Yeah, correct guess!\n";
    return status::right;
  }
  if (prev_guess != (int)1e9)
  {
    if (abs(guess - answer) < abs(prev_guess - answer))
    {
      // closer than previous attempt
      std::cout << "Nop, it's hot though, try again: ";
      prev_guess = guess;
      return status::hot;
    }
    else
    {
      // further from previous attempt
      std::cout << "Nop, it's getting cold, try again: ";
      prev_guess = guess;
      return status::cold;
    }
  }
  else
  { 
    // It's the user's first (wrong) guess
    std::cout << ">>> Nop, try again: ";
    prev_guess = guess;
    return status::start;
  }
}

/*!
 * Starts the Game.
*/
void GameBrain::begin()
{
  int guess;
  std::cout << "Guess the Number: ";
  std::cin >> guess;
  while (make_guess(guess) != status::right)
  {
    std::cin >> guess;
  }
}