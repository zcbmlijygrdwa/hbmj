#include <iostream>
#include "Tile.hpp"
#include "HonorTile.hpp"


HonorTile::HonorTile()
{
    suit = -1;
}

HonorTile::HonorTile(int suit_in)
{
    suit = suit_in;
}


std::ostream& HonorTile::toString(std::ostream& o) const
{
    char* output;
    if(suit==suit_dong)
    output = (char*)"Dong";
    else if(suit==suit_nan)
    output = (char*)"Nan";
    else if(suit==suit_xi)
    output = (char*)"Xi";
    else if(suit==suit_bei)
    output = (char*)"Bei";
    else 
    output = (char*)"Unknown";


    o<<"suit[HonorTile]: "<<suit;
    return o;
}

