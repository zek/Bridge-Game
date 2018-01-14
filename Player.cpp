#include "Player.h"

void Player::setGame(Game *game) {
    _game = game;
}

void Player::giveCard(Card *card) {
    _hand.push_back(card);
}

void Player::discardHand() {

}

void Player::displayHand(int row) {
    cout << AdvancedConsole::Cursor(row, 0) << AdvancedConsole::Erase(AdvancedConsole::AC_ALL, AdvancedConsole::AC_LINE)
         << "Your Hand: ";
    for (Card *c: _hand) {
        cout << *c << "  ";
    }
    cout << endl << endl;

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
    if (available_cards.empty()) return _hand;
    return available_cards;
}

bool Player::hasColor(Color::Type color) {
    std::vector<Card *> available_cards;
    copy_if(_hand.begin(), _hand.end(), std::back_inserter(available_cards),
            [color](const Card *card) {
                return card->getColor() == color;
            });

    return !available_cards.empty();
}

Card *Player::playCard() {
    std::vector<Card *> available_cards = getAvailableCards(
            _game->getCurrentDeal()->getCurrentTrick()->getStartingColor());
    Card *card = makeDecision(available_cards);
    _hand.erase(std::find_if(_hand.begin(), _hand.end(), [card](Card *p) -> bool { return card == p; }));
    return card;
}

void Player::unserialize(nlohmann::json data) {
    auto deck = Game::getDeck();
    _name.assign(data["name"]);
    _hand.clear();
    for (const auto &c: data["hand"]) {
        _hand.push_back(deck[c]);
    }
}

json Player::serializeHand() {
    json hand;
    for (auto c: _hand) {
        hand += c->serialize();
    }
    return hand;
}

string Player::getName() {
    return _name;
}
