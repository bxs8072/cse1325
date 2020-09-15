#include "tile.h"
#include "board.h"

int main(int argc, char const *argv[])
{
    int NUM_OF_TILES = 0;

    std::cout << "Number of tiles: ";
    std::cin >> NUM_OF_TILES;

    Board _initBoard(NUM_OF_TILES);

    int _tile1, _tile2;

    int _guess = 0;

    while (!_initBoard.solved())
    {
        _guess++;

        std::cout << "Guess " << _guess << ", ";
        std::cout << "Select two unmatched tiles: ";
        std::cin >> _tile1 >> _tile2;

        if (_tile1 < NUM_OF_TILES && _tile2 < NUM_OF_TILES)
        {
            std::cout << _initBoard.attempt(_tile1, _tile2) << std::endl;
            std::cout << _initBoard.to_string() << std::endl;
        }
        else
        {
            std::cout << "Please enter correct guess." << std::endl;
        }
    }

    if (_initBoard.solved())
    {
        std::cout << "Total number of guess to complete the game was: " << _guess << std::endl;
    }
    return 0;
}
