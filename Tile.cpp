#include <iostream>
#include "Tile.hpp"


Tile::Tile()
{
    suit = -1;
}

Tile::Tile(int suit_in)
{
    suit = suit_in;
}


std::ostream& Tile::toString(std::ostream& o) const
{
    o<<"suit[Tile]: "<<suit;
    return o;
}

