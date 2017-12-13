#include "Deal.h"
#include <algorithm>

Deal::Deal(array<Card *, 52> deck, array<Player *, 4> players, int dealer) :
        _deck(deck),
        _players(players),
        _dealer(dealer) {};

void Deal::dealing() {
    //shuffling
    random_shuffle(begin(_deck), end(_deck));

    //distribution
    int i = (_dealer + 1) % 4;
    for (Card *c: _deck) {
        _players[i]->giveCard(c);
        i = (i + 1) % 4;
    }
}

void Deal::bidding() {
    int speaker = (_dealer + 1) % 4;
    int nbrOfPass = 0;
    Contract *tmp_c;
    _contract = nullptr;
    while ((nbrOfPass < 3) || (nbrOfPass == 3 && _contract == nullptr)) {
        tmp_c = _players[speaker]->proposeContract(_contract);
        if (tmp_c == Contract::Pass()) {
            nbrOfPass++;
        } else if (_contract == nullptr || tmp_c > _contract) {
            nbrOfPass = 0;
            _contract = tmp_c;
            _contractor = speaker;
        } else {
            cout << "Error, contract lower than the previous one" << endl;
            nbrOfPass++;
        }
        speaker = (speaker + 1) % 4;
    }

}

void Deal::playing() {
    int first_player = (_contractor + 1) % 4;
    Trick *current_trick;
    Card *card_played;
    int current_player;

    //we play 13 tricks
    for (int round = 0; round < 13; round++) {
        //the four players have to play a trick
        cout << "Round: " << round << endl;
        current_trick = new Trick();
        for (int i = 0; i < 4; i++) {
            current_player = (first_player + i) % 4;
            card_played = _players[current_player]->playCard(current_trick->getStartingColor(),
                                                             Color::NOTRUMP);//todo: need trump color

            cout << *_players[current_player] << ": " << *card_played << endl;
            current_trick->addCard(card_played, current_player);
        }

        first_player = current_trick->getWinner(_contract);
        cout << "Winner: " << *_players[first_player] << endl << endl;
        _players[first_player]->getTeam()->winTrick(current_trick);
    }

}

void Deal::scoring() {
    //Teams North-South and East-West
    Team *Contracting, *Defending;
    Contracting = _players[_contractor]->getTeam();
    Defending = _players[(_contractor + 1) % 4]->getTeam();
    //todo: counting points and adding them
    Contracting->newDeal();
    Defending->newDeal();
}

void Deal::play() {
    dealing();
    bidding();
    playing();
    scoring();
}


