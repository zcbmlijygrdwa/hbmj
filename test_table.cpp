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

bool judger2(vector<Tile>& ts)
{
    bool isJiang = false;
    int keiCount = 0;
    int shunCount = 0;

    int sumSuits[9][10] = {}; // ={};  will give a zero-initialized array.

    for(int i = 0  ; i < ts.size() ; i++ )
    {
        sumSuits[ts[i].num-1][ts[i].suit]++;
    }


    for(int i = 1  ; !isJiang && i < SingleGroup::group_size; i++ )
    {
        for(int j = 0; !isJiang && j<9;j++)
        {
            if(sumSuits[j][i]==2&&(j==1||j==4||j==7))
            {
                isJiang = true;
                sumSuits[j][i] -= 2;
            }
        }
    }


    for(int i = 1  ; i < SingleGroup::group_size; i++ )
    {
        for(int j = 0; j<9;j++)
        {
            if(sumSuits[j][i]==3)
            {
                if(!isJiang&&(j==1||j==4||j==7))
                {
                    isJiang = true;
                    sumSuits[j][i] -= 2;
                }
                else
                {
                    keiCount++;
                    sumSuits[j][i] -= 3;
                }
            }
        }
    }

    if(!isJiang)
    {
        return false;
    }


    for(int i = 0  ; i < SingleGroup::group_size; i++ )
    {
        for(int j = 0; j<7;j++)
        {
            //cout<<"j = "<<j<<endl;
            if(sumSuits[j][i]>0&&sumSuits[j+1][i]>0&&sumSuits[j+2][i]>0)
            {
                shunCount++;
                j+=2;
            }
        }
    }



    cout<<"isJiang = "<<isJiang<<", keiCount = "<<keiCount<<", shunCount = "<<shunCount<<endl;

    if(isJiang&&(keiCount+shunCount==4))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void getJiang(vector<Tile>& ts,vector<Tile>& js)
{
    js.clear();

    for(int i = 0  ; i < ts.size() ; i++ )
    {
        Tile t = ts[i];
        if(t.num==2||t.num==5||t.num==8)
        {
            js.push_back(t);
        }
    }
}


int string2suit(std::string s)
{
    for(int i = 0; i < SingleGroup::group_size ; i++)
    {
        if(s.compare(SingleGroup::suit_name_set[i])==0)
        {
            return i;
        }
    }
    return -1;
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
    vector<Tile> my_jiang_set;

    Table t;

    bool isFound = false;
    while(!isFound)
    {
        t.reset_table();

        my_tile_set.clear();

        int temp_suit = 0;
        int temp_num = 0;
        for(int i = 0 ;i<14;i++)
        {
            if(rand()%34<27)
            {
                temp_suit = rand() %SingleGroup::simple_size;
                temp_num = rand() % Table::table_size + 1;

            }
            else
            {
                temp_suit = rand() %SingleGroup::honor_size + SingleGroup::simple_size;
                temp_num = 1;

            }

            t.discover_tile(temp_num,temp_suit);

            Tile t(temp_num,temp_suit);
            my_tile_set.push_back(t);
        }
        
        isFound = judger2(my_tile_set);
        cout<<"judger = "<<isFound<<endl;
    }

    sort_my_tiles(my_tile_set);
    cout<<"My tiles="<<endl;
    for(int i = 0 ; i<my_tile_set.size();i++)
    {
        cout<<my_tile_set[i].num<<", "<<SingleGroup::suit_name_set[my_tile_set[i].suit]<<endl;
    }



    return -1;
}
