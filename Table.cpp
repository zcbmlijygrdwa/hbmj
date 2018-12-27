#include <iostream>
#include "Table.hpp"


Table::Table()
{
    count_discovered = 0;
    count_undiscovered = count_total;
    Table::reset_table();
}

void Table::reset_table()
{
    for(int i = 0 ;i<table_size;i++)
    {
        table_known[i].reset_group_full(i);
        //table_unknown[i].reset_group_empty();
    }
}


void Table::vis_table()
{

    std::cout<<"--------------------------------------"<<std::endl;
    std::cout<<"**************************************"<<std::endl;
    std::cout<<std::endl;
    for(int i = 0 ;i<SingleGroup::group_size;i++)
    {
        std::cout<<"["<<table_known[0].suit_name_set[i]<<"]"<<std::endl;
        for(int j = 0; j<table_size;j++)
        {
            std::cout<<table_known[j].get_count(i)<<"\t";
        }
        std::cout<<std::endl;
    }
    std::cout<<"**************************************"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;

}

void Table::discover_tile(int num, int suit)
{
    table_known[num-1].fetch(suit);
    count_discovered ++;
    count_undiscovered --;
}

float Table::tile_prob(int num, int suit)
{
    float prob = 0;
    prob = table_known[num-1].get_count(suit)*1.0f/count_undiscovered;
}
