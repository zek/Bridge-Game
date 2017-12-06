#ifndef FINAL_COMPUTERPLAYER_H
#define FINAL_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : Player {
    Card* playCard();
    Contract proposeContract();

};


#endif //FINAL_COMPUTERPLAYER_H
