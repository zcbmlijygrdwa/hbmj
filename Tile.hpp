#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
    public:
        int suit;

        Tile();
        Tile(int suit_in);
        virtual std::ostream& toString(std::ostream& o) const;
};

#endif
