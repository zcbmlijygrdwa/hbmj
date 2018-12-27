#include <iostream>
#include "SingleGroup.hpp"

const std::string SingleGroup::suit_name_set[] = {
"character",
"bamboo",
"dot",
"dong",
"nan",
"xi",
"bei",
"zhong",
"fa",
"bai"};


SingleGroup::SingleGroup()
{
    SingleGroup::reset_group_empty();
}

void SingleGroup::reset_group_full(int num)
{
    if(num==0)
    {
        for(int i = 0 ; i<SingleGroup::group_size;i++)
        {
            data[i] = 4;
        }
    }
    else
    {
        for(int i = 0 ; i<SingleGroup::group_size;i++)
        {
            if(i<SingleGroup::dong)
            { 
                data[i] = 4;
            }
            else
            {
                data[i] = 0;
            } 
        }

    }
}

void SingleGroup::reset_group_empty()
{

    for(int i = 0 ; i<SingleGroup::group_size;i++)
    {
        data[i] = 0;
    }

}

int SingleGroup::get_count_group()
{
    int sum = 0;
    for(int i = 0 ; i<SingleGroup::group_size;i++)
    {
        sum += data[i];
    }
    return sum;
}

int SingleGroup::get_count(int suit)
{
    return data[suit];
}

void SingleGroup::fetch(int suit)
{
    data[suit]-=1;
}


void SingleGroup::put(int suit)
{
    data[suit]+=1;
}

std::ostream& SingleGroup::to_string(std::ostream& o)
{
    o<<std::endl;
    for(int i = 0 ; i<group_size;i++)
    { 
        o<<"data ["<<suit_name_set[i]<<"]: "<<data[i]<<std::endl;;
    }
    return o;   
}
