#include "board.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>
#include <cstdlib>

std::vector<std::string> words {
"bang", "beam", "bear", "cafe", "came",
"cold", "come", "cool", "date", "diet",
"door", "doth", "echo", "exes", "exit",
"face", "fame", "feed", "fire", "five",
"four", "free", "frog", "from", "game",
"goes", "good", "grit", "have", "heal",
"hear", "here", "hide", "hole", "home",
"hope", "huge", "keep", "kill", "lace",
"lame", "leek", "life", "live", "maps",
"mass", "mate", "maze", "move", "near",
"need", "nine", "once", "quit", "ques",
"race", "read", "reed", "reef", "rice",
"roof", "sins", "stay", "tame", "teen",
"tens", "tide", "tied", "tree", "twin",
"zero", "zips",
};

int myRandom(int i) {
    return std::rand() % i;
}

Board::Board(int tiles)
{
    std::srand(unsigned(std::time(0)));

    std::random_shuffle(words.begin(), words.end(), myRandom);

    std::vector<Tile> _initTiles = {};

    int _count = 0;
    int j = 0;

    //pushing same words twice from the words vector into tile list
    for (int i = 0; i < tiles; ++i)
    {
        ++_count;
        if (_count == 2)
        {
            ++j;
            for (int k = 0; k < _count; ++k)
            {
                _initTiles.push_back(Tile(words.at(j)));
            }
            _count = 0;
        }
    }

    std::random_shuffle(_initTiles.begin(), _initTiles.end(), myRandom);
    this->_tiles = _initTiles;
}

std::string Board::attempt(int tile1, int tile2)
{
    if (this->_tiles.at(tile1).match(this->_tiles.at(tile2)))
    {
        return this->_tiles.at(tile1).to_string() + " MATCHED " +
               this->_tiles.at(tile2).to_string();
    }
    else
    {
        return this->_tiles.at(tile1).word() + " " + this->_tiles.at(tile2).word();
    }
}

bool Board::solved()
{
    int _count_true = 0;

    for (Tile t : this->_tiles)
    {
        if (t.matched())
        {
            ++_count_true;
        }
    }
    return _count_true == this->_tiles.size();
}

std::string Board::to_string()
{
    std::string _output;

    std::vector<std::vector<Tile>> double_vector = {};
    std::vector<Tile> new_tile_list = {};

    for (int i = 0; i < this->_tiles.size(); i++)
    {
        new_tile_list.push_back(this->_tiles.at(i));

        if (new_tile_list.size() == 10)
        {
            double_vector.push_back(new_tile_list);
            new_tile_list.clear();
        }
    }

    int ROW_SIZE = this->_tiles.size() / 10;


    for (int j = 0; j < double_vector.size(); ++j)
        {   
            std::cout << "\t " << j;
        }

    for (int i = 0; i < ROW_SIZE; ++i)
    {   
        std::cout << "\n" << (i*10) << "\t";
        for (int j = 0; j < double_vector.size(); ++j)
        {   
            std::cout << double_vector.at(i).at(j).to_string() << "\t";
        }
        std::cout << std::endl;
    }
    return _output;
}