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
