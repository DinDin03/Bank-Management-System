#include <iostream>
#include <string>
using namespace std;

void print_binary_str(std::string decimal_number){
    int number = stoi(decimal_number);
    int count = 0;
    int array[8] = {0,0,0,0,0,0,0,0};
    while(number > 0){
        if(number%2==0){
            array[count] = 0;
        }
        else{
            array[count] = 1;
        }
        number = number/2;
        count++;
    }
    for(int i = 7;i>=0;i--){
        std::cout << array[i];
    }
    std::cout<<std::endl;
}