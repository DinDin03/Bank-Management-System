#include <iostream>
using namespace std;

extern int count_digits(int[4][4]);

int main(){
    int array[4][4] = {1,1,2,2,3,4,5,6,7,8,9,1,2,3,5,6};
    count_digits(array);
    return 0;
}