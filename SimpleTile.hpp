#ifndef SIMPLE_TILE_H
#define SIMPLE_TILE_H

#include <iostream>

class SimpleTile: public Tile
{
    public:
        int suit;
        int num;

        static const int suit_dot = 1;
        static const int suit_bamboo = 2;
        static const int suit_character = 3;

        SimpleTile();
        SimpleTile(int suit_in, int num_in);
        virtual std::ostream& toString(std::ostream& o) const;
};

#endif
