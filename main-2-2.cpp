#include <iostream>
using namespace std;

extern int binary_to_int(int[], int);

int main(){
    int array[8] = {1,0,1,1,0,1,1,0};
    int size = sizeof(array)/sizeof(int);
    std::cout << binary_to_int(array,size) << std::endl;
    return 0;
}