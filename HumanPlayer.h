#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const string name) : Player(name) {}

private:
    Card *makeDecision(Color::Type color, Color::Type trump_color, std::vector<Card *> available_cards);

    Contract *proposeContract(Contract *current_max);
};


#endif //FINAL_HUMANPLAYER_H
