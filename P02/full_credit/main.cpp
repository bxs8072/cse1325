#include <iostream>
#include <ctime>
#include <vector>

int main() {
    srand(time(NULL));
    int number_of_dice, number_of_faces, number_of_rolls;
    
    std::cout << "Number of dice? ";
    std::cin >> number_of_dice;

    std::cout << "Number of faces per dice? ";
    std::cin >> number_of_faces;

    std::cout << "Number of roll? ";
    std::cin >> number_of_rolls;


    for(int i=0; i < number_of_rolls; ++i ) {
        std::vector<int> myList;
        int sum = 0;

        std::cout << "Roll " + std::to_string(i) + ": ";

        for(int j=0; j<number_of_dice; ++j) {
            int RANDOM_RESULT = rand() % number_of_faces + 1;

            myList.push_back(RANDOM_RESULT); 
            sum = sum + RANDOM_RESULT;
            std::cout << RANDOM_RESULT << " ";
        }      
        std::cout << " Sum: " + std::to_string(sum) << std::endl;
    }
    return 0;
}