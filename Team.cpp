#include "Team.h"

Team::Team(Player *player1, Player *player2) {
    _players = {player1, player2};
    player1->setTeam(this);
    player2->setTeam(this);
    _gameScore = 0;
}

void Team::winTrick(Trick *tr) {
    _tricksWon.push_back(tr);
}

int Team::getGameScore() {
    return _gameScore;
}

void Team::addToGameScore(int n) {
    _gameScore += n;
}

void Team::newDeal() {
    _tricksWon.clear();
}

list<Trick *> Team::getWonTricks() {
    return _tricksWon;
}


