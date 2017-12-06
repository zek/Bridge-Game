#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED


namespace Color {
    enum Type {
        CLUB, DIAMOND, HEART, SPADE, NOTRUMP
    };

    static const Type All[] = {Type::CLUB, Type::DIAMOND, Type::HEART, Type::SPADE, Type::NOTRUMP};
}

#endif // COLOR_H_INCLUDED
