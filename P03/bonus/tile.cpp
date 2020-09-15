#include "tile.h"

int Tile::_width = -1;
std::string Tile::_blank;

Tile::Tile(std::string word) : _word(word), _matched(false)
{
    Tile::_width = word.size();
    
    std::string initBlank;
    for(int i=0; i<Tile::width(); ++i) {
        initBlank += "-";
    }
    Tile::_blank = initBlank;
}

std::ostream& operator<<(std::ostream& ost, const Tile& _tile) {
   return ost << &_tile._word;
}

bool Tile::operator == (const Tile& _tile) const {
    return this->_word == _tile._word;
}

bool Tile::operator != (const Tile& _tile) const {
    return !(this->_word == _tile._word);
}

bool Tile::match(Tile &_tile)
{
    if (*this == _tile)
    {
        this->_matched = true;
        _tile._matched = true;
        return true;
    }
    else
    {
        this->_matched = false;
        _tile._matched = false;
        return false;
    }
}

std::string Tile::word()
{
    return this->_word;
}

bool Tile::matched()
{
    return this->_matched;
}

int Tile::width()
{
    return Tile::_width;
}

std::string Tile::to_string()
{
    return this->matched() ? this->word() : Tile::_blank;
}