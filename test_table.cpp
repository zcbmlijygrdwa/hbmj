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

int cost_fun(vector<Tile>& ts,vector<int>& fixed)
{
    fixed.clear();

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
            //cout<<"sumSuits["<<j<<"]["<<i<<"] = "<<sumSuits[j][i]<<endl;
            if(sumSuits[j][i]==2&&(j==1||j==4||j==7))
            {
                isJiang = true;
                sumSuits[j][i] -= 2;

                for(int k = 0; k< ts.size() ;k++)
                {
                    if(ts[i].num-1==j&&ts[i].suit==i)
                    {
                        fixed.push_back(k);                
                    }
                } 
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

                for(int k = 0; k< ts.size() ;k++)
                {
                    if(ts[i].num-1==j&&ts[i].suit==i)
                    {
                        fixed.push_back(k);                
                    }
                } 
            }
        }
    }



    int shunCost = 3;;
    for(int i = 0  ; i < SingleGroup::group_size; i++ )
    {
        for(int j = 0; j<7;j++)
        {
            //cout<<"j = "<<j<<endl;
            shunCost = 3;;
            if(sumSuits[j][i]>0)
            {
                shunCost--;
            }

            if(sumSuits[j+1][i]>0)
            {
                shunCost--;
            }
            if(sumSuits[j+2][i]>0)
            {
                shunCost--;
            }
            if(shunCost==0)
            {
                shunCount++;
                j+=2;

                for(int k = 0; k< ts.size() ;k++)
                {
                    if(ts[i].num-1==j&&ts[i].suit==i)
                    {
                        fixed.push_back(k);                
                    }
                } 

            }
        }
    }



    //cout<<"isJiang = "<<isJiang<<", keiCount = "<<keiCount<<", shunCount = "<<shunCount<<endl;

    int cost = 0;

    if(!isJiang)
    {
        cost+=2;
    }
    cost+=(4-keiCount-shunCount);
    return cost;
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
vector<Tile> ts_min;
int cost_min;
void explore2(vector<Tile>& ts,Table table)
{
    int temp_num = 0;
    int temp_suit = 0;
    int idx = 0;

    vector<int> fix;

    while(cost_min>0)
    {
        idx = rand()%14;
        temp_num = rand()%9+1;
        temp_suit = rand()%10;

        //vector<Tile> ts = ts;
        Tile tt = Tile(temp_num,temp_suit);
        if(!tt.isValid())
        {
            continue;
        }

        //check available
        if(table.check_tile_remain(temp_num,temp_suit)==0)
        {
            continue;
        }

        //check if is fixed element
        bool isFixed = false; 
        for(int i = 0 ; i< fix.size();i++)
        {
            if((ts[fix[i]].num==temp_num)&&(ts[fix[i]].suit==temp_suit))
            {
                isFixed = true;
                break;
            }
        }
        if(isFixed)
        {
            //cout<<"fixed!"<<endl;
            continue;
        }
        else
        {
            //cout<<"not fixed..."<<endl;

        }

        table.discover_tile(temp_num,temp_suit);
        table.return_tile(ts[idx].num,ts[idx].suit);
        //cout<<"talbe.count_undiscovered = "<<table.count_undiscovered<<endl;
        ts[idx] = tt;
        //cout<<"new: "<<ts[idx].num<<", "<<SingleGroup::suit_name_set[ts[idx].suit]<<endl;

        //cout<<"["<<prev_idx<<","<<prev_i<<","<<prev_j<<"]My tiles="<<endl;
        int cost = cost_fun(ts,fix);
        if(cost<cost_min)
        {
            judger2(ts);
            cost_min = cost;
            ts_min = ts;
            cout<<"temp cost = "<<cost<<", cost_min = "<<cost_min<<endl;
        }
    }
    cout<<"cost not decrease"<<endl;
}


void explore(vector<Tile>& ts,int prev_cost, int prev_idx, int prev_j, int prev_i)
{
    for(int idx = prev_idx+1;cost_min!=0&&idx<ts.size();idx++)
    {
        for(int j = 0; cost_min!=0&&j<10;j++)
        {
            for(int i = 1; cost_min!=0&&i<=9;i++)
            {
                //vector<Tile> ts = ts;
                Tile tt = Tile(i,j);
                if(!tt.isValid())
                {
                    continue;
                }
                ts[idx] = tt;
                //cout<<"new: "<<ts[idx].num<<", "<<SingleGroup::suit_name_set[ts[idx].suit]<<endl;

                //cout<<"["<<prev_idx<<","<<prev_i<<","<<prev_j<<"]My tiles="<<endl;
                vector<int> fix;
                int cost = cost_fun(ts,fix);
                if(cost<prev_cost)
                {
                    cout<<"["<<idx<<","<<i<<","<<j<<"]My tiles="<<endl;
                    for(int ii = 0 ; ii<ts.size();ii++)
                    {
                        cout<<ts[ii].num<<", "<<SingleGroup::suit_name_set[ts[ii].suit]<<endl;
                    }
                    if(cost<cost_min)
                    {
                        judger2(ts);
                        cost_min = cost;
                        ts_min = ts;
                        //sort_my_tiles(ts);
                        cout<<"temp cost = "<<cost<<", cost_min = "<<cost_min<<endl;
                    } 
                }
                if(cost_min>0)
                { 
                    explore(ts,cost_min,idx,j,i);
                }               

            }
        }
    }
    //cout<<"cost not decrease"<<endl;
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

    vector<int> fixed;
    int cost = cost_fun(my_tile_set,fixed);
    cout<<"cost = "<<cost<<endl;
    sort_my_tiles(my_tile_set);
    cout<<"My tiles="<<endl;
    for(int i = 0 ; i<my_tile_set.size();i++)
    {
        cout<<my_tile_set[i].num<<", "<<SingleGroup::suit_name_set[my_tile_set[i].suit]<<endl;
    }


    ts_min = my_tile_set;
    cost_min = cost;

    explore2(my_tile_set,t);

    sort_my_tiles(ts_min);

    cout<<"cost_min = "<<cost_min<<endl;
    cout<<"My MIN tiles="<<endl;
    for(int i = 0 ; i<ts_min.size();i++)
    {
        cout<<ts_min[i].num<<", "<<SingleGroup::suit_name_set[ts_min[i].suit]<<endl;
    }



    return -1;
}
