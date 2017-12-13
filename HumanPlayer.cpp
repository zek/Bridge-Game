#include "HumanPlayer.h"

Contract *HumanPlayer::proposeContract(Contract *current_max) {
    int color, trick_amount;
    if (current_max) {
        cout << "Current contract: " << *current_max << endl;
    }
    for (int c : Color::All) {
        cout << c << " : " << Color::Values[c] << endl;
    }
    cout << "Choose : ";
    cin >> color;
    cout << "Trick Amount: ";
    cin >> trick_amount;
    return new Contract(trick_amount, Color::All[color]);
}

Card *HumanPlayer::playCard(Color::Type color, Color::Type trump_color) {
    cout << "Your Hand: " << endl;
    int i = 0, card_no;
    for (Card *c: _hand) {
        cout << i++ << ":" << *c << endl;
    }
    cout << "Play: ";
    cin >> card_no;
    Card* card = _hand[card_no];
    _hand.erase(std::find_if(_hand.begin(), _hand.end(), [card](Card *p) -> bool { return card == p; }));
    return card;
}
