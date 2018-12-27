#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>       /* time */


#include "SimpleTile.hpp"
#include "HonorTile.hpp"

using namespace std;

std::ostream& operator <<(std::ostream& o, const Tile& t)
{
    return t.toString(o);
}


int main()
{
    vector<SimpleTile> simples;
    vector<HonorTile> honors;

    string userInput;

    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    //iSecret = rand() % 10 + 1;

    int temp_num= 0;
    int temp_suit= 0;

    for(int i = 0 ; i<13;i++)
    {
        //cin>>userInput;
        //cout<<"userInput!"<<endl;
        //cout<<"userInput = "<<userInput<<endl;

        if(rand() % 34<27)
        {
            temp_num = rand() % 9 + 1;
            temp_suit=rand() % 3 + 1;
            simples.push_back(SimpleTile(temp_num,temp_suit));
        }
        else
        {
            temp_suit=rand() % 4 + 1;
            honors.push_back(HonorTile(temp_suit));

        }


    }

    for(int i = 0 ; i<simples.size();i++)
    {
        cout<<"simples["<<i<<"]:"<<simples[i]<<endl;
    }
    
    for(int i = 0 ; i<honors.size();i++)
    {
        cout<<"honors["<<i<<"]:"<<honors[i]<<endl;
    }


    return -1;
}
