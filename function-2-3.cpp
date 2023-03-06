#include <iostream>
using namespace std;
void two_five_nine(int array[], int n){
    int twos = 0;
    int fives = 0;
    int nines = 0;
    if(n < 1){
        std::cout << "2:0;5:0;9:0" << std::endl;
    }

    for(int i = 0; i < n; i++){
        if(array[i] == 2){
            twos++;
        }
        if(array[i] == 5){
            fives++;
        }
        if(array[i] == 9){
            nines++;
        }
    }
    std::cout << "2:" << twos << ";5:" << fives << ";9:" << nines << ";" << std::endl;
    return;

}