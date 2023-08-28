#include "brain.h"

GameBrain::GameBrain(int maxint) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distr(1,maxint);
    this->answer = distr(gen);
    this->prev_guess = (int)1e9;
}

int GameBrain::make_guess(int guess) {
    if (guess == answer) {
        std::cout << ">>> Yeah, correct guess!\n";
        return status::right;
    }
    if (prev_guess != (int)1e9) {
        if (abs(guess - answer) < abs(prev_guess - answer)) {
            std::cout << "Nop, it's hot though, try again: ";
            prev_guess = guess;
            return status::hot;
        } else {
            std::cout << "Nop, it's getting cold, try again: ";
            prev_guess = guess;
            return status::cold;
        }
    } else {
        std::cout << ">>> Nop, try again: ";
        prev_guess = guess;
        return status::start;
    }
}

void GameBrain::begin() {
    int guess;
    std::cout << "Guess the Number: ";
    std::cin >> guess;
    while (make_guess(guess) != status::right) std::cin >> guess;
}