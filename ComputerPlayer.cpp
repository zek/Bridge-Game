#include "ComputerPlayer.h"
#include "misc.h"
#include <algorithm>

Card *ComputerPlayer::playCard(Color::Type color, Color::Type trump_color) {
/*
    std::vector<Card *> available_cards;
    copy_if(_hand.begin(), _hand.end(), std::back_inserter(available_cards),
            [](const Card *card) { return card->getColor() == color || card->getColor() == trump_color; });

    vector<Card *>::iterator random_it = select_randomly(_hand.begin(), _hand.end());
    Card *random = *random_it;
    _hand.erase(random_it);
    return random;*/
    return nullptr;
}

Contract *ComputerPlayer::proposeContract(Contract* current_max) {
    Contract* contract = new Contract(1, Color::NOTRUMP);
    return contract;
}
