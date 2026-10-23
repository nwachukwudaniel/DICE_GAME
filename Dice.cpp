#include "Dice.hpp"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    score = 1;
}

int Dice::get_score() const {
    return score;
}

void Dice::roll() {
    score = rand() % 6 + 1;
}