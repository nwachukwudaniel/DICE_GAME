#include "Player.hpp"

Player::Player(const std::string& new_name) {
    name = new_name;
    total_score = 0;
}

std::string Player::get_name() const {
    return name;
}

int Player::get_value() const {
    return dice.get_score();
}

int Player::get_total_score() const {
    return total_score;
}

void Player::take_turn() {
    dice.roll();
    total_score += dice.get_score();
}

void Player::reset_score() {
    total_score = 0;
}