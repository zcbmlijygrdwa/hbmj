#include <iostream>
#include "Tile.hpp"
#include "SimpleTile.hpp"


SimpleTile::SimpleTile()
{
    suit = -1;
    num = -1;
}

SimpleTile::SimpleTile(int num_in,int suit_in)
{
    suit = suit_in;
    num = num_in;
}


std::ostream& SimpleTile::toString(std::ostream& o) const
{
    char* output;
    if(suit==Dot)
    output = (char*)"Dot";
    else if(suit==Bamboo)
    output = (char*)"Bamboo";
    else if(suit==Character)
    output = (char*)"Character";
    else
    output = (char*)"Unknown";

    o<<"[SimpleTile]: "<<num<<" "<<output;
    return o;
}

