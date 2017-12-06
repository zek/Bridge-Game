#include "Contract.h"

bool Contract::operator>(Contract *lhs, Contract *rhs) {
    if (lhs->getTricksAmount() > rhs->getTricksAmount()) {
        return true;
    } else if (lhs->getTricksAmount() > rhs->getTricksAmount()) {
        return lhs->getColor() > lhs->getColor();
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
    return !operator>(lhs, rhs);
}

bool Contract::operator==(Contract *lhs, Contract *rhs) {
    return lhs->getColor() == rhs->getColor() && lhs->getTricksAmount() == rhs->getTricksAmount();
}

Contract::Contract(int amountOfTricks, COLOR color) {
    _tricksAmount = amountOfTricks;
    _color = color;
}

Contract::Contract() {
    _tricksAmount = 0;
    _color = COLOR::NOTRUMP;
}

Contract *Contract::Pass() const {
    return new Contract(); // Todo: Should be singleton
}
