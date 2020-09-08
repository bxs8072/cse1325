#include <iostream>
#include <ctime>
#include <list>

int get_random_result(int number_of_faces) {
    return rand() % number_of_faces + 1;
}

int get_index_value(std::list<int> myList, int index) {
    std::list<int>::iterator it = myList.begin();
    for(int i=0; i<index; i++) {
        ++it;
    }
    return *it;
}

std::string get_output_data(int a, int b, int c) {
    std::string  str_a = a==0 ? "" : std::to_string(a) + " ";
    std::string  str_b = b==0 ? "" : std::to_string(b) + " ";
    std::string  str_c = c==0 ? "" : std::to_string(c) + " ";
    return str_a + str_b + str_c;
}

std::string get_ascending_order_output(std::list<int> myList) {
    std::string output;
    for(int i : myList) {
        output = output + " " + std::to_string(i);
    }
    return output;
}

int get_sum(std::list<int> myList) {
    int sum = 0;
    for(int i : myList) {
        sum = sum + i;
    }
    return sum;
}

double get_mean(std::list<int> myList) {
    int sum = get_sum(myList);
    int total_numbers = myList.size();
    double mean = (double) (sum/(1.0 * total_numbers));
    return mean;
}

double get_median(std::list<int> myList) {
    auto myList_front = myList.begin();

    int n = myList.size();
    if(n%2 != 0) {
        return (double) 1.0 * get_index_value(myList,n/2);
    }
    return (double) (get_index_value(myList, (n-1)/2) + get_index_value(myList,n/2)) / 2.0;
}

int get_mode(std::list<int> myList) {
    int number = get_index_value(myList,0);
    int mode = number;
    int count=1;
    int countMode=1;
    for(int i=0; i<myList.size(); i++) {
        if(get_index_value(myList,i) == number) {
            ++count;
        }
        else {
            if(count > countMode) {
                countMode = count;
                mode = number;
            }
            count = 1;
            number = get_index_value(myList, i);
        }
    }
    return mode;
}

int main() {
    srand(time(NULL));
    int number_of_dice, number_of_faces1, number_of_faces2, number_of_faces3, number_of_rolls;
    
    std::cout << "Number of dice? ";
    std::cin >> number_of_dice;

    std::cout << "Number of faces per dice1? ";
    std::cin >> number_of_faces1;

    std::cout << "Number of faces per dice2? ";
    std::cin >> number_of_faces2;

    std::cout << "Number of faces per dice3? ";
    std::cin >> number_of_faces3;

    std::cout << "Number of roll? ";
    std::cin >> number_of_rolls;

    std::list<int> datas;
    for(int i=0; i < number_of_rolls; ++i ) {
        int a, b, c, sum;
        for(int j=0; j<number_of_dice; ++j) {
             a = number_of_faces1 == 0 ? 0 : get_random_result(number_of_faces1);
             b = number_of_faces2 == 0 ? 0 : get_random_result(number_of_faces2);
             c = number_of_faces3 == 0 ? 0 : get_random_result(number_of_faces3);
             sum = a + b + c;
        }   
        datas.push_back(sum);
        std::cout << get_output_data(a,b,c) << " = " + std::to_string(sum) << std::endl;
    }
    datas.sort();
    std::cout << get_ascending_order_output(datas) <<std::endl;
    std::cout << "Sum: " << get_sum(datas) <<std::endl;
    std::cout << "Mean: " << get_mean(datas) <<std::endl;
    std::cout << "Median: " << get_median(datas) <<std::endl;
    std::cout << "Mode: " << get_mode(datas) <<std::endl;
    return 1;
}