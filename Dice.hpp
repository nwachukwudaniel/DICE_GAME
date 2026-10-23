#ifndef DICE_HPP
#define DICE_HPP

class Dice {
private:
    int score;

public:
    Dice();

    int get_score() const;

    void roll();
};

#endif