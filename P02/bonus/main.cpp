
#include <iostream>
#include <ctime>
#include <vector>
#include "die.h"

int main() {
    srand(time(NULL));

    int number_of_dice, number_of_faces, number_of_rolls;

    std::cout << "Number of dice? ";
    std::cin >> number_of_dice;

    std::cout << "Number of faces per dice? ";
    std::cin >> number_of_faces;

    std::cout << "Number of roll? ";
    std::cin >> number_of_rolls;

    for (int i = 0; i < number_of_rolls; ++i) {
        int sum = 0;
        std::vector<Die> datas;

        std::cout << "Roll " + std::to_string(i) + ": ";

        for (int j = 0; j < number_of_dice; ++j) {   
            Die myDie(number_of_faces);
            myDie.roll();
            datas.push_back(myDie);
            sum = sum + myDie.get_value();
            std::cout << myDie.get_value() << " ";
        }
        
        std::cout << " Sum: " + std::to_string(sum) << std::endl;
    }
    return 0;
}