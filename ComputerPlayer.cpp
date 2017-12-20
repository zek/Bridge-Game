#include "ComputerPlayer.h"
#include "misc.h"

Card *ComputerPlayer::makeDecision(Color::Type color, Contract *contract, std::vector<Card *> available_cards, Trick* trick) {
   
	vector<Card *>::iterator random_it = select_randomly(available_cards.begin(), available_cards.end());
	Card* random = *random_it;


	cardsOnTable = trick->get_cards();

	
	if (cardsOnTable.empty() == false) {

		if (hasColor(color)) {
			if (hasGreater(contract, available_cards) == true)
				return theGreatestAvailable(contract, available_cards);
			else
				if (hasContractColor(contract, available_cards))
					return theLowestAvailable(contract, contractColor(contract, available_cards));
				else
					return theLowestAvailable(contract, available_cards);
		}
		else
			if (hasContractColor(contract, available_cards))
				return theLowestAvailable(contract, contractColor(contract, available_cards));
			else
				return theLowestAvailable(contract, available_cards);
	}
	else
	
		return random;

}

bool ComputerPlayer::hasContractColor(Contract *contract, vector<Card *> available_cards) {
	bool hasContractCol = false;
	vector<Card *>::iterator iter = available_cards.begin();
	Card* card = *iter;

	//does the Player have the contract color? 
	for (++iter; iter != available_cards.end(); ++iter) {
		if (card->getColor() == contract->getColor()) {
			hasContractCol = true;
			break;
		}

		card = *iter;
	}

	return hasContractCol;
}


vector<Card*> ComputerPlayer::contractColor(Contract *contract, vector<Card *> available_cards) {
	vector<Card *>::iterator iter = available_cards.begin();
	vector<Card*> contractColor;
	Card* card = *iter;

	//create vector of only available contract colors
	for (++iter; iter != available_cards.end(); ++iter) {
		if (card->getColor() == contract->getColor()) {
			contractColor.push_back(card);
		}

		card = *iter;
	}

	return contractColor;
}


bool ComputerPlayer::hasGreater(Contract *contract, vector<Card *> available_cards) {

	bool isGreater = false;


	Card* greatestAvail = theGreatestAvailable(contract, available_cards);
	Card* greatestTable = greatestOnTable(contract);

	if (greatestAvail->isBigger(greatestTable, contract))
		isGreater = true;
	else
		isGreater = false;
		
	return isGreater;
}

Card* ComputerPlayer::greatestOnTable(Contract *contract) {
	vector<Card *>::iterator iter = cardsOnTable.begin();
	Card* greatest = *iter;

	//greatest Card on the table
	Card* tmp = *iter;
	for (++iter; iter != cardsOnTable.end(); ++iter) {
		tmp = *iter;
		if (tmp->isBigger(greatest, contract))
			greatest = tmp;

		//std::cout << ' ' << greatest->getValue() << '\n';
	}

	return greatest;
}


Card* ComputerPlayer::theGreatestAvailable(Contract *contract, vector<Card *> available_cards) {
	vector<Card *>::iterator it = available_cards.begin();
	Card* greatest = *it;

	//greatest Card in available cards
	Card* tmp = *it;
	for (++it; it != available_cards.end(); ++it) {
		tmp = *it;
		if (tmp->isBigger(greatest, contract))
			greatest = tmp;
		//std::cout << ' ' << greatest->getValue() << '\n';
	}

	return greatest;
}

Card* ComputerPlayer::theLowestAvailable(Contract *contract, vector<Card *> available_cards) {
	vector<Card *>::iterator it = available_cards.begin();
	Card* lowest = *it;

	//lowest Card in available cards
	Card* tmp = *it;
	for (++it; it != available_cards.end(); ++it) {
		tmp = *it;
		if (lowest->isBigger(tmp, contract))
			lowest = tmp;
	}

	return lowest;
}

Contract *ComputerPlayer::proposeContract(Contract *current_max) {
    if (current_max == nullptr) {
        Contract *contract = new Contract(1, Color::CLUB);
        cout << *this << " proposed: " << *contract << endl;
        return contract;
    } else {
        cout << *this << " passed" << endl;
        return Contract::Pass();
    }
}

ComputerPlayer::ComputerPlayer(const string name) : Player(name) {
}
