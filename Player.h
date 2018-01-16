#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Card.h"
#include "Team.h"
#include "Trick.h"
#include "Contract.h"
#include "Game.h"
#include "Serializable.h"
#include "Memento.h"
#include "misc.h"

class Game;

class Team;

using namespace std;

class Player : public Serializable {
protected:
    vector<Card *> _hand;
    Team *_team;
    bool _isDummy;
    string _name;
    Game *_game;


public:
    void setGame(Game *game);

    void giveCard(Card *card);

    void discardHand();

    void displayHand(int row = 0);

    virtual Contract *proposeContract(Contract *current_max) = 0;

    Card *playCard();

    virtual Card *makeDecision(std::vector<Card *> available_cards) = 0;

    Player();

    void setTeam(Team *team);

    Team *getTeam();

    string getName();

    std::vector<Card *> getAvailableCards(Color::Type color);

    bool hasColor(Color::Type color);

    friend std::ostream &operator<<(std::ostream &os, const Player &c);

    void unserialize(nlohmann::json data);

    void setName(const string name);

protected :
    json serializeHand();
};


#endif //FINAL_PLAYER_H
