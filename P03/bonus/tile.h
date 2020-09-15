#ifndef tile
#define tile
#include <iostream>

class Tile
{
public:
    Tile(std::string word);
    bool match(Tile &_tile);
    std::string word();
    bool matched();
    static int width();
    std::string to_string();

private:
    std::string _word;
    bool _matched;
    static int _width;
    static std::string _blank;
};

#endif