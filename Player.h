#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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


    void discardCard(Card *pCard);

    Card *playCard(Color::Type color, Color::Type trump_color);

    virtual Card *makeDecision(Color::Type color, Color::Type trump_color, std::vector<Card *> available_cards) = 0;

    Player(const string name);

    void setTeam(Team *team);

    Team *getTeam();

    std::vector<Card *> getAvailableCards(Color::Type color);

    friend std::ostream &operator<<(std::ostream &os, const Player &c);
};


#endif //FINAL_PLAYER_H
