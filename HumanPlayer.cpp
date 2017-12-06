#include "HumanPlayer.h"

Contract* HumanPlayer::proposeContract() {
    return nullptr;
}

Card *HumanPlayer::playCard() {
    return nullptr;
}

HumanPlayer::HumanPlayer(const string &name) : Player(name) {}
