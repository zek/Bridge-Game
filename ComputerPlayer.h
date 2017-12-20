#ifndef FINAL_COMPUTERPLAYER_H
#define FINAL_COMPUTERPLAYER_H

#include "Player.h"
#include "Contract.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(const string name);


	Card *makeDecision(Color::Type color, Contract *contract, std::vector<Card *> available_cards, Trick* trick);
	Contract *proposeContract(Contract *current_max);

	bool hasGreater(Contract *contract, vector<Card *> available_cards);
	bool hasContractColor(Contract *contract, vector<Card *> available_cards);



	Card* theLowestAvailable(Contract *contract, vector<Card *> available_cards);
	Card* greatestOnTable(Contract *contract);
	Card* theGreatestAvailable(Contract *contract, vector<Card *> available_cards);
	vector<Card*> contractColor(Contract *contract, vector<Card *> available_cards);

private:
	static int n;
   


	vector<Card*> cardsOnTable;

   
};


#endif //FINAL_COMPUTERPLAYER_H
