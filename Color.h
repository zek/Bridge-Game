#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <string>

namespace Color {
    enum Type {
        CLUB, DIAMOND, HEART, SPADE, NOTRUMP
    };

    static const std::string Values[] = {"CLUB", "DIAMOND", "HEART", "SPADE"};

    static const Type All[] = {Type::CLUB, Type::DIAMOND, Type::HEART, Type::SPADE};
}

#endif // COLOR_H_INCLUDED
