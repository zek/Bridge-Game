#ifndef FINAL_COMPUTERPLAYER_H
#define FINAL_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(const string name);

private:
    Card *makeDecision(Color::Type color, Color::Type trump_color, std::vector<Card *> available_cards);

    Contract *proposeContract(Contract *current_max);
};


#endif //FINAL_COMPUTERPLAYER_H
