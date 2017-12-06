#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"
#include "Card.h"

class HumanPlayer : Player {
    Contract proposeContract();

    Card* playCard();

};


#endif //FINAL_HUMANPLAYER_H
