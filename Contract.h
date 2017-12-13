#ifndef CONTRACT_H_INCLUDED
#define CONTRACT_H_INCLUDED

#include "Color.h"
#include <iostream>

class Contract {
private:
    int _tricksAmount;
    Color::Type _color;
    //Maybe an option, like double, etc ...
    static Contract *_pass;

    Contract();

public:
    static Contract *Pass();

    Contract(int amountOfTricks, Color::Type color);

    int getTricksAmount() const;
    //void setOption(ContractOption co);
    //ContractOption getContractOption();

    Color::Type getColor() const;

    friend std::ostream &operator<<(std::ostream &os, const Contract &c);
};

#endif // CONTRACT_H_INCLUDED
