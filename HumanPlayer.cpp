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

Card *HumanPlayer::makeDecision(Color::Type color, Color::Type trump_color, std::vector<Card *> available_cards) {
    cout << "Your Hand: " << endl;
    int i = 0, card_no;
    for (Card *c: available_cards) {
        cout << i++ << ":" << *c << endl;
    }
    cout << "Play: ";
    cin >> card_no;
    Card *card = available_cards[card_no];
    return card;
}
