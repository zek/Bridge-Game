#include "ComputerPlayer.h"
#include "misc.h"

Card *ComputerPlayer::playCard(Color::Type color, Color::Type trump_color) {
    std::vector<Card *> available_cards;
    copy_if(_hand.begin(), _hand.end(), std::back_inserter(available_cards),
            [color, trump_color](const Card *card) {
                return (card->getColor() == color));
                //return (card->getColor() == color) || (card->getColor() == trump_color);
            });

    if (available_cards.size() == 0) {
        vector<Card *>::iterator random_it = select_randomly(_hand.begin(), _hand.end());
        Card *random = *random_it;
        _hand.erase(random_it);
        return random;
    } else {
        vector<Card *>::iterator random_it = select_randomly(available_cards.begin(), available_cards.end());
        Card *random = *random_it;
        _hand.erase(std::find_if(_hand.begin(), _hand.end(), [random](Card *p) -> bool { return random == p; }));
        return random;
    }
}

Contract *ComputerPlayer::proposeContract(Contract *current_max) {
    if (current_max == nullptr) {
        Contract *contract = new Contract(1, Color::CLUB);
        cout << *this << " proposed: " << *contract << endl;
        return contract;
    } else {
        cout << *this << " passed" << endl;
        return Contract::Pass();
    }
}

ComputerPlayer::ComputerPlayer(const string name) : Player(name) {

}
