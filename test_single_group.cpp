#include <iostream>
#include "SingleGroup.hpp"
using namespace std;


ostream& operator <<(ostream& o, SingleGroup& s)
{
    return s.to_string(o);
}


int main()
{

    SingleGroup s;

    s.reset_group_full(0);
   
    cout<<"s = "<<s<<endl;
    
    s.reset_group_full(1);
   
    cout<<"s = "<<s<<endl;

    s.reset_group_full(2);
   
    cout<<"s = "<<s<<endl;


return -1;
}
