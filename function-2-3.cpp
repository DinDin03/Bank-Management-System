#include <iostream>
using namespace std;

int sum_if_palindrome(int integers[], int length){
    if(length <= 0){
        return false;
    }
    int sum = 0;
    for(int i = 0; i<length; i++){
        sum += integers[i];
    }
    std::cout << sum << std::endl;
    return 0;
}

int sum_array_elements(int integers[], int length){
    if(length <= 0){
        return false;
    }
    int sum2 = 0;
    for(int i = 0; i<length; i++){
        sum2 += integers[i];
    }
    std::cout << sum2 << std::endl;
    return 0;
}

bool is_palindrome(int integers[], int length)
{
    if(length <= 0){
        return false;
    }
    int ispalindrome = 0;
    for (int i = 0; i < length / 2 && length != 0; i++)
    {
        if(integers[i] != integers[length-1-i]){
            ispalindrome = 1;
            break;
        }
    }
    if(ispalindrome == 1){
        sum_array_elements(integers,length);
        return -2;
    }
    else
        sum_if_palindrome(integers,length);
        return 0;
}

