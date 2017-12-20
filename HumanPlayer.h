#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const string name) : Player(name) {}

private:
    Card *makeDecision(std::vector<Card *> available_cards);

    Contract *proposeContract(Contract *current_max);
};


#endif //FINAL_HUMANPLAYER_H
