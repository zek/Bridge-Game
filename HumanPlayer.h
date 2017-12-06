#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"
#include "Card.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const string &name);

private:
    Contract* proposeContract();

    Card* playCard();

};


#endif //FINAL_HUMANPLAYER_H
