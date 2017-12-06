#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H

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
    void giveCard(Card *card) {
        _hand.push_back(card);
    }

    void discardHand() {

    }

    void displayHand() {

    }

    virtual Contract *proposeContract(Contract* current_max) = 0;

    virtual Card *playCard(Color::Type color, Color::Type trump_color) = 0;

    Player(const string name) : _name(name) {
        _isDummy = false;
    }

    void setTeam(Team *team) {
        _team = team;
    }

    Team *getTeam() {
        return _team;
    }

};


#endif //FINAL_PLAYER_H
