#ifndef FINAL_TEAM_H
#define FINAL_TEAM_H

#include <array>
#include "Player.h"
#include "Trick.h"

class Player;

class Team {
private:
    string _name;
    array<Player *, 2> _players;
    list<Trick *> _tricksWon;
    int _gameScore;
public:
    Team(string name, Player *player1, Player *player2);

    void winTrick(Trick *t);

    void addToGameScore(int n);

    void newDeal();

    list<Trick *> getWonTricks() const ;

    array<Player *, 2> getPlayers() const;

    string getName() const;

    int getGameScore() const;

    friend std::ostream &operator<<(std::ostream &os, const Team &c);

};

#endif //FINAL_TEAM_H
