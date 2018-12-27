//g++ -o test_table test_table.cpp Table.cpp SingleGroup.cpp Tile.cpp && ./test_table

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>  //for std::sort


#include "Table.hpp"
#include "Tile.hpp"

using namespace std;


ostream& operator <<(ostream& o, SingleGroup& s)
{
    return s.to_string(o);
}

void sort_my_tiles(vector<Tile>& ts)
{
    std::sort(ts.begin(), ts.end());
}

int main()
{
    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    //iSecret = rand() % 10 + 1;

    vector<Tile> my_tile_set;

    Table t;

    t.vis_table();

    int temp_suit = 0;
    int temp_num = 0;

    for(int i = 0 ;i<13;i++)
    {
        if(rand()%34<27)
        {
            temp_suit = rand() %SingleGroup::simple_size;
            temp_num = rand() % Table::table_size + 1;
            t.discover_tile(temp_num,temp_suit);

        }
        else
        {
            temp_suit = rand() %SingleGroup::honor_size + SingleGroup::simple_size;
            temp_num = 1;
            t.discover_tile(temp_num,temp_suit);

        }

        Tile t(temp_num,temp_suit);
        my_tile_set.push_back(t);

        cout<<"temp_num = "<<temp_num<<", temp_suit = "<<temp_suit<<endl;
    }
    t.vis_table();

    cout<<"t.count_undiscovered = "<<t.count_undiscovered<<endl;

    cout<<"My tiles="<<endl;
    for(int i = 0 ; i<my_tile_set.size();i++)
    {
        cout<<my_tile_set[i].num<<", "<<SingleGroup::suit_name_set[my_tile_set[i].suit]<<endl;
    }

    sort_my_tiles(my_tile_set);

    cout<<"After sort, my tiles="<<endl;
    for(int i = 0 ; i<my_tile_set.size();i++)
    {
        cout<<my_tile_set[i].num<<", "<<SingleGroup::suit_name_set[my_tile_set[i].suit]<<endl;
    }

    cout<<"Prob of get["<<4<<" dot] = "<<t.tile_prob(4,SingleGroup::dot)<<endl;

    cout<<"Prob of get["<<5<<" dot] = "<<t.tile_prob(5,SingleGroup::dot)<<endl;




    return -1;
}
