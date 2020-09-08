#include <iostream>
#include <ctime>
#include <list>

    
int get_random_result(int number_of_faces) {
    return rand() % number_of_faces + 1;
}

std::string get_output_from_list(std::list<int> myList) {
    std::string output;
    for(int i : myList) {
        output = output + " " + std::to_string(i);
    }
    return output;
}

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
        std::list<int> myList;
        int sum = 0;
        for(int j=0; j<number_of_dice; ++j) {
             myList.push_back(get_random_result(number_of_faces)); 
             sum = sum + get_random_result(number_of_faces);
        }      
        std::cout << "Roll " + std::to_string(i) + ": " << get_output_from_list(myList) << " Sum: " + std::to_string(sum) << std::endl;
    }
    return 0;
}