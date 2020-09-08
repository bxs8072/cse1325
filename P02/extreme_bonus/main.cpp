#include <iostream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>


int get_random_result(int number_of_faces) {
    return rand() % number_of_faces + 1;
}

int get_sum(std::vector<int> myList) {
    int sum = 0;
    for(int i : myList) {
        sum = sum + i;
    }
    return sum;
}

double get_mean(std::vector<int> myList) {
    int sum = get_sum(myList);
    int total_numbers = myList.size();
    double mean = (double) (sum/(1.0 * total_numbers));
    return mean;
}

double get_median(std::vector<int> myList) {
    auto myList_front = myList.begin();

    int n = myList.size();
    if(n%2 != 0) {
        return (double) 1.0 * myList.at(n/2);
    }
    return (double) (myList.at((n-1)/2)+ myList.at(n/2)) / 2.0;
}

int get_mode(std::vector<int> myList) {
    int number = myList.at(0);
    int mode = number;
    int count=1;
    int countMode=1;
    for(int i=0; i<myList.size(); i++) {
        if(myList.at(i) == number) {
            ++count;
        }
        else {
            if(count > countMode) {
                countMode = count;
                mode = number;
            }
            count = 1;
            number = myList.at(i);
        }
    }
    return mode;
}

int main() {
    srand(time(NULL));
    int number_of_dice, number_of_rolls;
    
    std::cout << "Number of dice? ";
    std::cin >> number_of_dice;
    
    std::vector<int> dice_face_list;
    for(int i=0; i<number_of_dice; i++) {

        int number_of_faces;
        
        int DICE_NUMBER = i + 1;
        std::cout << "Number of faces per dice" << DICE_NUMBER << "?";
        std::cin >> number_of_faces;

        dice_face_list.push_back(number_of_faces);
    }

    std::cout << "Number of roll? ";
    std::cin >> number_of_rolls;

    std::vector<int> datas;
    for(int i=0; i < number_of_rolls; ++i ) {

        std::vector<int> myDatas;
        int sum = 0;

        for(int j=0; j<number_of_dice; ++j) {
           int RANDOM_VAUE = dice_face_list.at(j) == 0 ? 0 : get_random_result(dice_face_list.at(j));

           myDatas.push_back(RANDOM_VAUE);
           sum = sum + RANDOM_VAUE;

           std::string a_str = RANDOM_VAUE == 0 ? "" : std::to_string(RANDOM_VAUE); 
           std::cout << a_str << " ";
        }   

        datas.push_back(sum);
        
        std::cout << " = " + std::to_string(sum) << std::endl;
    }
    std::sort(datas.begin(), datas.end());

    for(int x : datas) {
        std::cout << x << " ";
    }
    std::cout <<std::endl;
    std::cout << "Sum: " << get_sum(datas) <<std::endl;
    std::cout << "Mean: " << get_mean(datas) <<std::endl;
    std::cout << "Median: " << get_median(datas) <<std::endl;
    std::cout << "Mode: " << get_mode(datas) <<std::endl;
    return 0;
}
