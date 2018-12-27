#ifndef SINGLE_GROUP
#define SINGLE_GROUP

#include <iostream>
#include <vector>
#include <string>

class SingleGroup
{
public:

    static const int  character = 0;
    static const int  bamboo = 1;
    static const int  dot = 2;

    static const int  dong = 3;
    static const int  nan = 4;
    static const int  xi = 5;
    static const int  bei = 6;

    static const int  zhong = 7;
    static const int  fa = 8;
    static const int  bai = 9;

    static const int  group_size = 10;
    static const int  simple_size = 3;
    static const int  honor_size = 7;


    static const std::string suit_name_set[];


    SingleGroup();

    void reset_group_empty();
    void reset_group_full(int num);
    
    int get_count_group();
    int get_count(int suit);
    void fetch(int suit);
    void put(int suit);

    std::ostream& to_string(std::ostream& o);
    
private:
    int data[group_size];

};



#endif
