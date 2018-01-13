#ifndef FINAL_HUMANPLAYER_H
#define FINAL_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const string name) : Player(name) {}

    nlohmann::json serialize() override {
        json data;
        data["name"] = _name;
        data["hand"] = serializeHand();
        data["isComputer"] = 0;
        return data;
    }

private:
    Card *makeDecision(std::vector<Card *> available_cards) override;

    Contract *proposeContract(Contract *current_max) override;
};


#endif //FINAL_HUMANPLAYER_H
