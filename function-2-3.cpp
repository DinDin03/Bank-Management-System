#include <iostream>
using namespace std;

bool is_palindrome(int integers[], int length)
int ispalindrome = 0;
{
    for (int i = 0; i < length / 2 && length != 0; i++)
    {
        if(integers[i] != integers[length-1-i]){
            ispalindrome = 1;
            break;
        }
    }
    if(ispalindrome == 1){
        std::cout << "IS NOT PALINDROME" << std::endl;
        return -2;
    }
    else
        std::cout << "IS PALINDROME" << std::endl;
}

int sum_if_palindrome(int integers[], )