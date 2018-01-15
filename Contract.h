#ifndef CONTRACT_H_INCLUDED
#define CONTRACT_H_INCLUDED

#include "Color.h"
#include "Serializable.h"
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


    json serialize(){
        return json({_tricksAmount, _color});
    }

    static Contract* unserialize(json data){
        return new Contract(data[0], data[1]);
    }

};

#endif // CONTRACT_H_INCLUDED
