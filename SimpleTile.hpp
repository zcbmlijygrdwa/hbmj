#ifndef SIMPLE_TILE_H
#define SIMPLE_TILE_H

#include <iostream>
#include "Tile.hpp"

class SimpleTile: public Tile
{
    public:
        int suit;
        int num;

        static const int Dot = 1;
        static const int Bamboo = 2;
        static const int Character = 3;

        SimpleTile();
        SimpleTile(int num_in, int suit_in);
        virtual std::ostream& toString(std::ostream& o) const;
};

#endif
