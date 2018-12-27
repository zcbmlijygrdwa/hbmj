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
    if(suit==Dong)
    output = (char*)"Dong";
    else if(suit==Nan)
    output = (char*)"Nan";
    else if(suit==Xi)
    output = (char*)"Xi";
    else if(suit==Bei)
    output = (char*)"Bei";
    else 
    output = (char*)"Unknown";


    o<<"[HonorTile]: "<<output;
    return o;
}

