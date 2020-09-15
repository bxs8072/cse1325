#include "board.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>
#include <cstdlib>

std::vector<std::string> words{
    "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face", "bang", "beam", "bear", "cafe", "came", "cold",
    "come", "date", "diet", "face"};

Board::Board(int tiles)
{
    std::srand(unsigned(std::time(0)));

    std::random_device rd;

    std::mt19937 g(rd());

    std::shuffle(words.begin(), words.end(), g);

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

    std::shuffle(_initTiles.begin(), _initTiles.end(), g);
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

    for (int i = 0; i < this->_tiles.size(); ++i)
    {
        std::string _out = this->_tiles.at(i).to_string() + "\n";
        _output += std::to_string(i) + ") " + _out;
    }
    return _output;
}