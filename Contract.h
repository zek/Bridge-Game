#ifndef CONTRACT_H_INCLUDED
#define CONTRACT_H_INCLUDED

#include "Color.h"

class Contract {
private:
    int _tricksAmount;
    COLOR _color;
    //Maybe an option, like double, etc ...
    static Contract *_pass;

    Contract();

public:
    static Contract *Pass() const;

    Contract(int amountOfTricks, COLOR color);

    bool operator>(Contract *lhs, Contract *rhs);

    bool operator<(Contract *lhs, Contract *rhs);

    bool operator==(Contract *lhs, Contract *rhs);

    int getTricksAmount();
    //void setOption(ContractOption co);
    //ContractOption getContractOption();

    bool getColor();
};

#endif // CONTRACT_H_INCLUDED
