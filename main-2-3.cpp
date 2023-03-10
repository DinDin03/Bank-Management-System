#include <iostream>
using namespace std;

extern bool is_palindrome(int[], int);
int main(){
    int array[4] = {1,0,1,1};
    int size = sizeof(array)/sizeof(int);
    if(size <= 0){
        return -1;
    }
    std::cout << is_palindrome(array,size) << std::endl;
    return 0;
}