#include <iostream>
using namespace std;

void transform(int n){
    int number = n;
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
        std::cout << array[i] << std::endl;
    }
}

int main(){
    int n = 76;
    transform(n);
    return 0;
}