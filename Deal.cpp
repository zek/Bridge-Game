#include "Deal.h"

Deal::Deal(array<Card *, 52> deck, array<Player *, 4> players, int dealer) :
        _deck(deck),
        _players(players),
        _dealer(dealer),
        _round(-1),
        _first_player(-1),
        _contract(nullptr),
        _contractor(-1),
        _state(State::Dealing) {};


Trick *Deal::getCurrentTrick() {
    return _currentTrick;
}

Contract *Deal::getContract() {
    return _contract;
}

void Deal::dealing() {
    makeMemento();
    //shuffling
    random_shuffle(begin(_deck), end(_deck));

    //distribution
    int i = (_dealer + 1) % 4;
    for (Card *c: _deck) {
        _players[i]->giveCard(c);
        i = (i + 1) % 4;
    }
    _state = State::Bidding;
    makeMemento();
}

void Deal::bidding() {
    int speaker = ((_contractor == -1 ? _dealer : _contractor) + 1) % 4;
    int nbrOfPass = 0;
    Contract *tmp_c;
    cout << AdvancedConsole::Erase();
    cout << AdvancedConsole::Cursor(0, 0) << "Proposes:";
    while ((nbrOfPass < 3) || (nbrOfPass == 3 && _contract == nullptr)) {
        cout << AdvancedConsole::Cursor(6, 0)
             << AdvancedConsole::Erase(AdvancedConsole::AC_ALL, AdvancedConsole::AC_LINE)
             << "Player: " << *_players[speaker] << endl;
        tmp_c = _players[speaker]->proposeContract(_contract);


        cout << AdvancedConsole::Cursor(speaker + 2, 0)
             << AdvancedConsole::Erase(AdvancedConsole::AC_ALL, AdvancedConsole::AC_LINE);
        if (tmp_c == Contract::Pass()) {
            cout << *_players[speaker] << " passed" << endl;
            nbrOfPass++;
        } else if (_contract == nullptr || tmp_c > _contract) {
            cout << *_players[speaker] << " proposed " << *tmp_c << endl;
            nbrOfPass = 0;
            _contract = tmp_c;
            _contractor = speaker;
            makeMemento();
        } else {
            cout << "Error, contract lower than the previous one" << endl;
            nbrOfPass++;
        }
        speaker = (speaker + 1) % 4;
    }

    _state = State::Playing;
    makeMemento();
}

void Deal::playing() {
    if (_first_player == -1) _first_player = (_contractor + 1) % 4;
    if (_round == -1) _round = 0;

    //we play 13 tricks
    while (_round < 13) {
        //the four players have to play a trick
        _currentTrick = new Trick();
        cout << AdvancedConsole::Cursor(0, 0)
             << AdvancedConsole::Erase(AdvancedConsole::AC_ALL, AdvancedConsole::AC_SCREEN) << "Round: " << _round + 1
             << endl;
        for (int i = 0; i < 4; i++) {
            int current_player = (_first_player + i) % 4;
            Card *card_played = _players[current_player]->playCard();
            cout << AdvancedConsole::Cursor(i+2, 0)
                 << AdvancedConsole::Erase(AdvancedConsole::AC_ALL, AdvancedConsole::AC_LINE)
                 << *_players[current_player] << ": " << *card_played << endl;
            _currentTrick->addCard(card_played, current_player);
        }

        _first_player = _currentTrick->getWinner(_contract);
        cout << "Winner: " << *_players[_first_player] << endl << endl;
        _players[_first_player]->getTeam()->winTrick(_currentTrick);

        _round++;
        makeMemento();

        cout << "Press any key to start next round..." << AdvancedConsole::Erase(AdvancedConsole::AC_AFTER, AdvancedConsole::AC_SCREEN);
        cin.ignore();
        cin.get();
    }

}

void Deal::scoring() {
    //Teams North-South and East-West
    Team *Contracting, *Defending;
    Contracting = _players[_contractor]->getTeam();
    Defending = _players[(_contractor + 1) % 4]->getTeam();

    // nbr of tricks made after the first 6
    int nbrOfOddTricks = static_cast<int>(Contracting->getWonTricks().size()) - 6;
    if (nbrOfOddTricks < _contract->getTricksAmount()) {
        //if contract is failed
        Defending->addToGameScore(scoreIfLost(nbrOfOddTricks));
    } else {
        // if contract is a success
        Contracting->addToGameScore(scoreIfWon(nbrOfOddTricks));
    }

    Contracting->newDeal();
    Defending->newDeal();

    _state = State::Completed;
    makeMemento();
}

int Deal::scoreIfWon(int nbrOfOddTricks) {
    int slamBonus;
    int contractPoints = 0;

    switch (_contract->getTricksAmount()) {
        case 6:
            slamBonus = 500;
            break;
        case 7:
            slamBonus = 1000;
            break;
        default :
            slamBonus = 0;
            break;
    }

    switch (_contract->getColor()) {
        case Color::CLUB:
        case Color::DIAMOND:
            contractPoints = 20 * nbrOfOddTricks;
            break;
        case Color::HEART:
        case Color::SPADE:
            contractPoints = 30 * nbrOfOddTricks;
            break;
        case Color::NOTRUMP:
            contractPoints = 10 + 30 * nbrOfOddTricks;
            break;
    }

    return contractPoints + slamBonus;
}

int Deal::scoreIfLost(int nbrOfOddTricks) {
    int requiredTricks = _contract->getTricksAmount();
    return 50 * (requiredTricks - nbrOfOddTricks);
}

void Deal::play() {
    switch (_state) {
        case State::Dealing:
            dealing();
        case State::Bidding:
            bidding();
        case State::Playing:
            playing();
            scoring();
            break;
        case State::Completed:
            break;
    }
}

Memento *Deal::makeMemento() {
    auto m = new Memento;
    m->setFirstPlayer(_first_player);
    m->setState(_state);
    m->setRound(_round);
    m->setPlayers(_players);
    m->setContract(_contract, _contractor);
    m->saveFile();
    return m;
}

void Deal::reset(Memento *mem) {
    _first_player = mem->first_player;
    _state = mem->state;
    _round = mem->round;
    int pi = 0;
    for (const auto &player:mem->players) {
        _players[pi]->unserialize(player);
        pi++;
    }

    _contractor = mem->contractor;
    if (!mem->contract.is_null()) {
        _contract = Contract::unserialize(mem->contract);
    }

    int i = 0;
    for (auto &player: _players) {
        player->unserialize(mem->players[i]);
        i++;
    }
}


