#include <iostream>
#include <ctime>
#include "die.h"

std::string display(int num_of_faces) {
    std::string a;
    Die die1(num_of_faces);
    for(int i=0; i<20; ++i) {
        die1.roll();
        a = a + std::to_string(die1.get_value()) + " ";
    }
    return a;
}

int main() {
    srand(time(NULL));
    std::cout << "d4: " << display(4) << std::endl;
    std::cout << "d6: " << display(6) << std::endl;
    std::cout << "d8: " << display(8) << std::endl;
    std::cout << "d12: " << display(12) << std::endl;
    std::cout << "d20: " << display(20) << std::endl;
    return 0;
}