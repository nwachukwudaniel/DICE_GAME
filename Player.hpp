#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Dice.hpp"

class Player {
private:
    std::string name;
    Dice dice;
    int total_score;

public:
    Player(const std::string& new_name);

    std::string get_name() const;
    int get_value() const;
    int get_total_score() const;

    void take_turn();
    void reset_score();
};

#endif