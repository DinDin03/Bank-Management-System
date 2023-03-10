#include <iostream>
#include <math.h>
using namespace std;
int binary_to_int(int binary_digits[], int number_of_digits)
{
    int index = 0;
    int decimal =0;
    for (int i = number_of_digits-1; i >= 0; i--)
    {
        decimal += binary_digits[i]*(pow(2,index));
        index++;
    }
    return decimal;
}