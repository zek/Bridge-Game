#include "ComputerPlayer.h"
#include "misc.h"

Card *ComputerPlayer::makeDecision(Color::Type color, Color::Type trump_color, std::vector<Card *> available_cards) {
    vector<Card *>::iterator random_it = select_randomly(available_cards.begin(), available_cards.end());
    Card *random = *random_it;
    return random;
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
