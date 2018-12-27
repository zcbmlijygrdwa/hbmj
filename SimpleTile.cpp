#include <iostream>
#include "Tile.hpp"
#include "SimpleTile.hpp"


SimpleTile::SimpleTile()
{
    suit = -1;
    num = -1;
}

SimpleTile::SimpleTile(int suit_in,int num_in)
{
    suit = suit_in;
    num = num_in;
}


std::ostream& SimpleTile::toString(std::ostream& o) const
{
    char* output;
    if(suit==suit_dot)
    output = (char*)"Dot";
    else if(suit==suit_bamboo)
    output = (char*)"Bamboo";
    else if(suit==suit_character)
    output = (char*)"Character";
    else
    output = (char*)"Unknown";

    o<<"suit[SimpleTile]: "<<output<<", num = "<<num;
    return o;
}

