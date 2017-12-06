#ifndef FINAL_TEAM_H
#define FINAL_TEAM_H

#include <array>
#include "Player.h"
#include "Trick.h"

class Player;

class Team {
private:
    array<Player*, 2> _players;
    list<Trick*> _tricksWon;
    int _gameScore;
public:
    Team(Player *player1, Player *player2);

    int winTrick(Trick *t) {
        return 0;
    }

    int getGameScore() {
        return 0;
    }

    void addToGameScore(int n) {

    }

    void newDeal() {

    }

    list<Trick *> getWonTricks() {
        list<Trick *> list;
        return list;
    }

};


#endif //FINAL_TEAM_H
