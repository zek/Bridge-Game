#include "Player.h"

void Player::giveCard(Card *card) {
    _hand.push_back(card);
}

void Player::discardHand() {

}

void Player::displayHand() {

}

std::ostream &operator<<(std::ostream &os, const Player &c) {
    return os << c._name;
}

Team *Player::getTeam() {
    return _team;
}

void Player::setTeam(Team *team) {
    _team = team;
}

Player::Player(const string name) : _name(name) {
    _isDummy = false;
}

std::vector<Card *> Player::getAvailableCards(Color::Type color) {
    std::vector<Card *> available_cards;
    copy_if(_hand.begin(), _hand.end(), std::back_inserter(available_cards),
            [color](const Card *card) {
                return card->getColor() == color;
            });
    if (available_cards.size() == 0) return _hand;
    return available_cards;
}

void Player::discardCard(Card *card) {
    _hand.erase(std::find_if(_hand.begin(), _hand.end(), [card](Card *p) -> bool { return card == p; }));
}

Card *Player::playCard(Color::Type color, Color::Type trump_color) {
    std::vector<Card *> available_cards = getAvailableCards(color);
    Card *card = makeDecision(color, trump_color, available_cards);
    discardCard(card);
    return card;
}
