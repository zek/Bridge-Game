#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const string name) : Player(name) {}

private:
    Contract *proposeContract(Contract* current_max) {
        return nullptr;
    }

    Card *playCard(Color::Type color, Color::Type trump_color) {
        return nullptr;
    }

};


#endif //FINAL_HUMANPLAYER_H
