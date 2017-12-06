#include "Contract.h"

bool Contract::operator>(Contract *lhs, Contract *rhs) {
    if (lhs->getTricksAmount() > rhs->getTricksAmount()) {
        return true;
    } else if (lhs->getTricksAmount() == rhs->getTricksAmount()) {
        return lhs->getColor() > rhs->getColor();
    }
    return false;
}


int Contract::getTricksAmount() {
    return _tricksAmount;
}

bool Contract::getColor() {
    return _color;
}

bool Contract::operator<(Contract *lhs, Contract *rhs) {
    if (lhs->getTricksAmount() < rhs->getTricksAmount()) {
        return true;
    } else if (lhs->getTricksAmount() == rhs->getTricksAmount()) {
        return lhs->getColor() < rhs->getColor();
    }
    return false;
}

bool Contract::operator==(Contract *lhs, Contract *rhs) {
    return lhs->getColor() == rhs->getColor() && lhs->getTricksAmount() == rhs->getTricksAmount();
}

Contract::Contract(int amountOfTricks, COLOR color) {
    if (amountOfTricks < 1){
        _tricksAmount = 1;
    } else if (amountOfTricks > 6){
        _tricksAmount = 6;
    } else {
        _tricksAmount = amountOfTricks;
    }
    _color = color;
}

Contract::Contract() {
    _tricksAmount = 0;
    _color = COLOR::NOTRUMP;
}

Contract *Contract::Pass() const {
    if (_pass==nullptr){
        _pass = new Contract();
    }
    return _pass;
}
