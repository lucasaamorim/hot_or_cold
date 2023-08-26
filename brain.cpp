#include "brain.h"

GameBrain::GameBrain(int maxint) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distr(1,maxint);
    this->answer = distr(gen);
    this->prev_guess = (int)1e9;
}

int GameBrain::make_guess(int guess) {
    if (guess == this->answer) {
        std::cout << ">>> Yeah, correct guess!\n";
        return 0;
    }
    std::cout << ">>> Nop,";
    if (prev_guess != (int)1e9) {
        if (abs(guess - this->answer) < abs(prev_guess - this->answer)) {
            std::cout << "it's hot though, try again:";
        }
    } else {
        std::cout << "try again:";
    }
}