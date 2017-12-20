#include "ComputerPlayer.h"
#include "misc.h"

Card *ComputerPlayer::makeDecision(std::vector<Card *> available_cards) {
   
	this->available_cards = available_cards;
	cardsOnTable = _game->getCurrentDeal()->getCurrentTrick()->getCards();

	vector<Card *>::iterator random_it = select_randomly(available_cards.begin(), available_cards.end());
	Card* random = *random_it;


	
	if (cardsOnTable.empty() == false) {
		if (hasColor(_game->getCurrentDeal()->getCurrentTrick()->getStartingColor())) {
			if (hasGreater() == true)
				return theGreatestAvailable();
			else
				if (hasContractColor())
					return theLowestAvailable(contractColor());
				else
					return theLowestAvailable(available_cards);
		}
		else
			if (hasContractColor())
				return theLowestAvailable(contractColor());
			else
				return theLowestAvailable(available_cards);
	}
	else	
		return random;
}

bool ComputerPlayer::hasContractColor() {
	bool hasContractCol = false;
	vector<Card *>::iterator iter = available_cards.begin();
	Card* card = *iter;

	//does the Player have the contract color? 
	for (++iter; iter != available_cards.end(); ++iter) {
		if (card->getColor() == _game->getCurrentDeal()->getContract()->getColor()) {
			hasContractCol = true;
			break;
		}
		card = *iter;
	}

	return hasContractCol;
}


vector<Card*> ComputerPlayer::contractColor() {
	vector<Card *>::iterator iter = available_cards.begin();
	vector<Card*> contractColor;
	Card* card = *iter;

	//create vector of only available contract colors
	for (++iter; iter != available_cards.end(); ++iter) {
		if (card->getColor() == _game->getCurrentDeal()->getContract()->getColor()) {
			contractColor.push_back(card);
		}
		card = *iter;
	}

	return contractColor;
}


bool ComputerPlayer::hasGreater() {

	bool isGreater = false;


	Card* greatestAvail = theGreatestAvailable();
	Card* greatestTable = greatestOnTable();

	if (greatestAvail->isBigger(greatestTable, _game->getCurrentDeal()->getContract() ))
		isGreater = true;
	else
		isGreater = false;
		
	return isGreater;
}

Card* ComputerPlayer::greatestOnTable() {
	vector<Card *>::iterator iter = cardsOnTable.begin();
	Card* greatest = *iter;

	//greatest Card on the table
	Card* tmp = *iter;
	for (++iter; iter != cardsOnTable.end(); ++iter) {
		tmp = *iter;
		if (tmp->isBigger(greatest, _game->getCurrentDeal()->getContract() ))
			greatest = tmp;

		//std::cout << ' ' << greatest->getValue() << '\n';
	}

	return greatest;
}


Card* ComputerPlayer::theGreatestAvailable() {
	vector<Card *>::iterator it = available_cards.begin();
	Card* greatest = *it;

	//greatest Card in available cards
	Card* tmp = *it;
	for (++it; it != available_cards.end(); ++it) {
		tmp = *it;
		if (tmp->isBigger(greatest, _game->getCurrentDeal()->getContract() ))
			greatest = tmp;
		//std::cout << ' ' << greatest->getValue() << '\n';
	}

	return greatest;
}

Card* ComputerPlayer::theLowestAvailable(vector<Card *> available_cards) {
	vector<Card *>::iterator it = available_cards.begin();
	Card* lowest = *it;

	//lowest Card in available cards
	Card* tmp = *it;
	for (++it; it != available_cards.end(); ++it) {
		tmp = *it;
		if (lowest->isBigger(tmp, _game->getCurrentDeal()->getContract() ))
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
