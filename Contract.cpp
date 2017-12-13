#include "Contract.h"

Contract* Contract::_pass = new Contract();

int Contract::getTricksAmount() const {
    return _tricksAmount;
}

Color::Type Contract::getColor() const {
    return _color;
}

bool operator>(const Contract& lhs, const Contract& rhs) {
    if (lhs.getTricksAmount() > rhs.getTricksAmount()) {
        return true;
    } else if (lhs.getTricksAmount() == rhs.getTricksAmount()) {
        return lhs.getColor() > rhs.getColor();
    }
    return false;
}

bool operator<(const Contract& lhs, const Contract& rhs) {
    if (lhs.getTricksAmount() < rhs.getTricksAmount()) {
        return true;
    } else if (lhs.getTricksAmount() == rhs.getTricksAmount()) {
        return lhs.getColor() < rhs.getColor();
    }
    return false;
}

bool operator==(const Contract& lhs, const Contract& rhs) {
    return lhs.getColor() == rhs.getColor() && lhs.getTricksAmount() == rhs.getTricksAmount();
}

Contract::Contract(int amountOfTricks, Color::Type color) {
    if (amountOfTricks < 1) {
        _tricksAmount = 1;
    } else if (amountOfTricks > 6) {
        _tricksAmount = 6;
    } else {
        _tricksAmount = amountOfTricks;
    }
    _color = color;
}

Contract::Contract() {
    _tricksAmount = 0;
    _color = Color::NOTRUMP;
}

Contract *Contract::Pass() {
    return _pass;
}

std::ostream &operator<<(std::ostream &os, const Contract &c) {
    return os << c._tricksAmount << " " << Color::Values[c._color];
}
