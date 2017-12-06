#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Team.h"

class Team;

using namespace std;

class Player {
protected:
    vector<Card *> _hand;
    Team *_team;
    bool _isDummy;
    string _name;
public:
    void giveCard(Card *card);

    void discardHand();

    void displayHand();

    virtual Contract *proposeContract(Contract *current_max) = 0;

    virtual Card *playCard(Color::Type color, Color::Type trump_color) = 0;

    Player(const string name);

    void setTeam(Team *team);

    Team *getTeam();

    friend std::ostream &operator<<(std::ostream &os, const Player &c);
};


#endif //FINAL_PLAYER_H
