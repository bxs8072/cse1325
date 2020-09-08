#include <iostream>
#include <ctime>
#include <vector>
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
    std::vector<int> facesList = {4, 6, 8, 12, 20};
    for(int x: facesList) {
        std::cout << "d" << x << ": " 
        << display(x)
        << std::endl;
    }
    return 0;
}