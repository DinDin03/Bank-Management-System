#include <iostream>
using namespace std;

extern bool is_array_palindrome(int[],int);

int main(){
    int array[4] = {1,0,0,1};
    int length = sizeof(array)/sizeof(int);
    is_array_palindrome(array,length);
}