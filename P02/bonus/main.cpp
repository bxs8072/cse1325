
#include <iostream>
#include <ctime>
#include <list>
#include "die.h"

std::string get_output_from_list(std::list<Die> myList) {
    std::string output;
    for(Die x: myList) {
        output = output + " " + std::to_string(x.get_value());
    }
    return output;
}

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
        int sum = 0;
        std::list<Die> datas;
    
        for (int j = 0; j < number_of_dice; ++j)
        {   
            Die myDie(number_of_faces);
            myDie.roll();

            datas.push_back(myDie);

            sum = sum + myDie.get_value();
        }
        std::cout << "Roll " + std::to_string(i) + ":"
                  << get_output_from_list(datas)
                  << " Sum: " + std::to_string(sum) << std::endl;
    }
    return 0;
}