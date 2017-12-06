#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H

#include <string>
#include "Card.h"
#include "Team.h"

using namespace std;

class Player {
protected:
    list<Card> _hand = nullptr;
    Team *_team = nullptr;
    bool _isDummy = false;
    string _name;
public:
    void giveCard(Card *card);

    virtual Card *playCard(COLOR) = 0;

    void discardHand();

    void displayHand();

    virtual Contract *proposeContract() = 0;

    Player(string name) : _name(name) {

    }

    void setTeam(Team *team) {
        _team = team;
    }

    Team *getTeam() {
        return _team;
    }

};


#endif //FINAL_PLAYER_H
