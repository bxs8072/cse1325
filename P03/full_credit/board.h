#ifndef board
#define board
#include <iostream>
#include <vector>
#include "tile.h"

class Board
{
public:
    Board(int tiles);
    std::string attempt(int tile1, int tile2);
    bool solved();
    std::string to_string();

private:
    std::vector<Tile> _tiles;
};

#endif