#include "SingleGroup.hpp"


using namespace std;

class Table
{
public:
    static const int table_size = 9; 
    static const int count_total = 136;  //（3×9+7) * 4
    Table();
    void reset_table();
    void vis_table();

    void discover_tile(int num, int suit);
    float tile_prob(int num, int suit);

    

private:
    int count_discovered;
    int count_undiscovered;
    SingleGroup table_known[table_size];
    SingleGroup table_unknown[table_size];
};
