#ifndef FINAL_COMPUTERPLAYER_H
#define FINAL_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(const string &name);

private:
    Card* playCard();
    Contract* proposeContract();

};


#endif //FINAL_COMPUTERPLAYER_H
