#ifndef FINAL_COMPUTERPLAYER_H
#define FINAL_COMPUTERPLAYER_H

#include "Player.h"
#include "Contract.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(const string name);



private:
	static int n;
   
	Card *makeDecision(std::vector<Card *> available_cards);
	Contract *proposeContract(Contract *current_max);

	bool hasGreater();
	bool hasContractColor();



	Card* theLowestAvailable(vector<Card*> available_cards);
	Card* greatestOnTable();
	Card* theGreatestAvailable();
	vector<Card*> contractColor();

	vector<Card *> available_cards;
	vector<Card*> cardsOnTable;

   
};


#endif //FINAL_COMPUTERPLAYER_H
