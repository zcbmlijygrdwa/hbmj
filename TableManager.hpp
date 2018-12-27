#incldue <vector>
using namespace std;

class Table
{
public:
    int total_count;

    void fetch_simple(int num, int suit);
    void fetch_honor(int suit);

    void get_count_suit(int suit);
    void get_count_num(int num);

    void get_count_honor(int honor_suit);
    void get_count_simple(int simple_num, int simple_suit);
    
    void get_count_know();
    void get_count_unknow();
    void get_count_total();

    

};
