#include <iostream>

int size_of_variable_star_arr(){
    int *arr = new int[3];
    std::cout << sizeof(arr) << std::endl;
    delete arr;
    return 0;
}