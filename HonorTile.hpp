#ifndef HONOR_TILE_H
#define HONOR_TILE_H

#include <iostream>
#include "Tile.hpp"

class HonorTile: public Tile
{
    public:
        int suit;

        static const int Dong = 1;
        static const int Nan = 2;
        static const int Xi = 3;
        static const int Bei = 4;

        HonorTile();
        HonorTile(int suit_in);
        virtual std::ostream& toString(std::ostream& o) const;
};

#endif
