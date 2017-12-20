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

class Game;
class Team;

using namespace std;

class Player {
protected:
    vector<Card *> _hand;
    Team *_team;
    bool _isDummy;
    string _name;
	Game* _game;


public:
	void setGame(Game* game);

    void giveCard(Card *card);

    void discardHand();

    void displayHand();

    virtual Contract *proposeContract(Contract *current_max) = 0;


    void discardCard(Card *pCard);

    //Card *playCard(Color::Type color, Contract *contract, Trick* trick);

	Card *playCard();

    virtual Card *makeDecision(std::vector<Card *> available_cards) = 0;

    Player(const string name);

    void setTeam(Team *team);

    Team *getTeam();

    std::vector<Card *> getAvailableCards(Color::Type color);

	bool hasColor(Color::Type color);

    friend std::ostream &operator<<(std::ostream &os, const Player &c);
};


#endif //FINAL_PLAYER_H
