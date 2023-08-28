/*!
 * This program implements the game Hot or Cold.
 * @author Selan
 * @date August 23rd, 2023.
 */

#include <iostream>
#include "brain.h"

//== Data structures
static constexpr short default_max_guess_value{ 30 };  //!< Default max guess
static constexpr short max_guess_value{ 100 };         //!< Max guess value.

//== Functions

/// Display basic instructions on how to run the program.
void usage() {
  std::cout << "\nUsage: ./hot_cold [<upper_limit>]\n\n";
  std::cout << "where <upper_limit> is the max guess value (default: 30).\n";
  std::cout << "the guess range is definied as [1,<upper_limit>].\n\n";
}

/*!
 * Display the game rules.
 * @param max_value Max guess value.
 */
void display_game_rules(int max_value) {
  std::cout << "===================================================\n";
  std::cout << "Welcome to the Hot-Cold Guess game, copyright 2023.\n";
  std::cout << "---------------------------------------------------\n";
  std::cout << "These are the game rules:\n";
  std::cout << "    * I’ll choose a random number in [1," << max_value
            << "]. Your job is to guess that number.\n";
  std::cout << "    * From the second guess onward, I’ll tell you if your guess\n";
  std::cout << "      is hot (closer than the previous guess) or cold (farther from\n";
  std::cout << "      the previous guess).\n";
  std::cout << "    * If you wish to quit the game, just type in a negative number.\n";
  std::cout << "      Good luck!\n";
  std::cout << "----------------------------------------------------\n";
}

/// Process the command line arguments.
int process_arguments(int argc, char* argv[]) {
  // Define a default value here.
  int user_max_guess{default_max_guess_value};
  // Too many arguments.
  if (argc > 2) {
    std::cerr << ">>> Wrong number of arguments.\n";
    usage();
    exit(1);
  }
  // We received the max guess value from command line.
  if (argc == 2) {
    // TODO: Assumindo que o valor é válido, por enquanto.
    user_max_guess = std::atoi(argv[1]);
    if (user_max_guess > ::max_guess_value or user_max_guess < 1) {
      std::cout << ">>> You provided an invalid max guess value. Choose a value in: [1," << max_guess_value
                << "]\n";
      usage();
      exit(1);
    }
  }
  return user_max_guess;
}

//== main program

int main(int argc, char* argv[]) {
  auto max_guess = process_arguments(argc, argv);
  display_game_rules(max_guess);
  GameBrain GB(max_guess);
  GB.begin();
  return 0;
}
