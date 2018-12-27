#include <iostream>
#include "Table.hpp"
using namespace std;


ostream& operator <<(ostream& o, SingleGroup& s)
{
    return s.to_string(o);
}


int main()
{

    Table t;
   
    t.vis_table();

    t.discover_tile(1,SingleGroup::dot);
    t.discover_tile(2,SingleGroup::character);
    t.discover_tile(2,SingleGroup::bamboo);
    t.discover_tile(4,SingleGroup::dot);

    t.vis_table();


    cout<<"Prob of get["<<4<<" dot] = "<<t.tile_prob(4,SingleGroup::dot)<<endl;

    cout<<"Prob of get["<<5<<" dot] = "<<t.tile_prob(5,SingleGroup::dot)<<endl;

return -1;
}
