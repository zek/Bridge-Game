#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"
#include <algorithm>

class HumanPlayer : public Player {
public:
    HumanPlayer(const string name) : Player(name) {}

private:
    Contract *proposeContract(Contract* current_max);

    Card *playCard(Color::Type color, Color::Type trump_color);

};


#endif //FINAL_HUMANPLAYER_H
