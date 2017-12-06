#ifndef FINAL_CARDVALUE_H
#define FINAL_CARDVALUE_H

#include <string>

namespace CardValue {
    enum Type {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
    };

    static const std::string Values[] = {"2", "3", "4", "5", "6",
                                         "7", "8", "9", "10", "JACK",
                                         "QUEEN", "KING", "ACE"};

    static const Type All[] = {Type::ACE, Type::TWO, Type::THREE, Type::FOUR, Type::FIVE, Type::SIX,
                               Type::SEVEN, Type::EIGHT, Type::NINE, Type::TEN, Type::JACK,
                               Type::QUEEN, Type::KING};
}



#endif //FINAL_CARDVALUE_H
