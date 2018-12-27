#include "Tile.hpp"


Tile::Tile()
{
    num = -1;
    suit = -1;
}

Tile::Tile(int num_in, int suit_in)
{
    num = num_in;
    suit = suit_in;
}

bool Tile::operator <(const Tile& rhs)
{
    if(this->suit<rhs.suit)
    {
        return true;
    }
    else if(this->suit>rhs.suit)
    {
        return false;
    }
    else
    {
        if(this->num<=rhs.num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
