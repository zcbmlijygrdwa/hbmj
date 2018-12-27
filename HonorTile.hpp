#ifndef HONOR_TILE_H
#define HONOR_TILE_H

#include <iostream>

class HonorTile: public Tile
{
    public:
        int suit;

        static const int suit_dong = 1;
        static const int suit_nan = 2;
        static const int suit_xi = 3;
        static const int suit_bei = 4;

        HonorTile();
        HonorTile(int suit_in);
        virtual std::ostream& toString(std::ostream& o) const;
};

#endif
