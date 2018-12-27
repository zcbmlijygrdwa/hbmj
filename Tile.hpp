class Tile
{
    public:
        int num;
        int suit;

        Tile();
        Tile(int num_in, int suit_in);
        bool isValid();
        bool operator <(const Tile& rhs);
};
