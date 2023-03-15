#include <iostream>

int size_of_array_arr(){
    int *arr = new int[3];
    int sum = 0;
    for(int i =0;i<sizeof(arr)/sizeof(int);i++){
        sum += sizeof(arr[i]);
    }
    std::cout << sum << std::endl;
    return 0;
}