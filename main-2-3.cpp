#include <iostream>
using namespace std;

extern bool is_palindrome(int[], int);
int main(){
    int array[4] = {1,0,1,1};
    int size = sizeof(array)/sizeof(int);
    std::cout << is_palindrome(array,size) << std::endl;
    return 0;
}