#ifndef FINAL_TEAM_H
#define FINAL_TEAM_H


#include "Player.h"
#include "Trick.h"

class Team {
private:
    Player *players[2];
    list<Trick *> tricksWon;
    int gameScore;
public:
    int winTrick(Trick *t);

    int getGameScore();

    void addToGameScore(int n);

    void newDeal();

    list<Trick *> getWonTricks();
};


#endif //FINAL_TEAM_H
