
#include <iostream>
#include <ctime>
#include "die.h"

int main()
{
    srand(time(NULL));

    int number_of_dice, number_of_faces, number_of_rolls;

    std::cout << "Number of dice? ";
    std::cin >> number_of_dice;

    std::cout << "Number of faces per dice? ";
    std::cin >> number_of_faces;

    std::cout << "Number of roll? ";
    std::cin >> number_of_rolls;

    for (int i = 0; i < number_of_rolls; ++i)
    {
        int sum;
        Die d1(number_of_faces), d2(number_of_faces), d3(number_of_faces);
        for (int j = 0; j < number_of_dice; ++j)
        {
            d1.roll();
            d2.roll();
            d3.roll();
            sum = d1.get_value() + d2.get_value() + d3.get_value();
        }
        std::cout << "Roll " + std::to_string(i) + ": "
                  << d1.get_value() << " "
                  << d2.get_value() << " "
                  << d3.get_value() << " "
                  << " Sum: " + std::to_string(sum) << std::endl;
    }
    return 0;
}