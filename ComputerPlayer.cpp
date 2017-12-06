#include "ComputerPlayer.h"
#include "misc.h"
#include <algorithm>

Card *ComputerPlayer::playCard(Color::Type color, Color::Type trump_color) {
    std::vector<Card *> available_cards;
    copy_if(_hand.begin(), _hand.end(), std::back_inserter(available_cards),
            [color, trump_color](const Card *card) { return card->getColor() == color || card->getColor() == trump_color; });

    vector<Card *>::iterator random_it = select_randomly(_hand.begin(), _hand.end());
    Card *random = *random_it;
    _hand.erase(random_it);
    return random;
}

Contract *ComputerPlayer::proposeContract(Contract *current_max) {
    if (current_max == nullptr) {
        Contract *contract = new Contract(1, Color::NOTRUMP);
        return contract;
    } else {
        return Contract::Pass();
    }
}
