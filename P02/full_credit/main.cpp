#include <iostream>
#include <ctime>

    
int get_random_result(int number_of_faces) {
    return rand() % number_of_faces + 1;
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
        int a, b, c, sum;
        for(int j=0; j<number_of_dice; ++j) {
             a = get_random_result(number_of_faces);
             b = get_random_result(number_of_faces);
             c = get_random_result(number_of_faces);
             sum = a + b + c;
        }      
        std::cout << "Roll " + std::to_string(i) + ": " << a << " " << b << " " << c << " " << " Sum: " + std::to_string(sum) << std::endl;
    }
    return 0;
}