#include <iostream>
using namespace std;

extern int sum_min_max(int[], int);

int main(){
    int array[8] = {-1,1,5,6,7,8,9,0};
    int size = sizeof(array)/sizeof(int);
    if(size <= 0){
        return -1;
    }
    std::cout << sum_min_max(array,size) << std::endl;
    return 0;
}