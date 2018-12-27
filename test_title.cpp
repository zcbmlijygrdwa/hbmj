#include <iostream>
#include "Tile.hpp"
#include "SimpleTile.hpp"
#include "HonorTile.hpp"

std::ostream& operator <<(std::ostream& o, const Tile& t)
{
    return t.toString(o);
}


using namespace std;


int main()
{

//Tests for Tile
Tile default_tile;

cout<<"default_tile = "<<default_tile<<endl;


Tile custom_tile(2);

cout<<"custom_tile = "<<custom_tile<<endl;


//Tests for SimpleTile
SimpleTile default_simple_tile;

cout<<"default_simple_tile = "<<default_simple_tile<<endl;


SimpleTile custom_simple_tile(2,SimpleTile::Dot);

cout<<"custom_simple_tile = "<<custom_simple_tile<<endl;



//Tests for HonorTile
cout<<"HonorTile.Dong = "<<HonorTile::Dong<<endl;

HonorTile default_honor_tile;

cout<<"default_honor_tile = "<<default_honor_tile<<endl;


HonorTile custom_honor_tile(HonorTile::Dong);

cout<<"custom_honor_tile = "<<custom_honor_tile<<endl;

return -1;
}
