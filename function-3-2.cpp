#include <bits/stdc++.h>
using namespace std;

int median_array(int array[], int n, int sorting)
{

    std::sort(array, array + sorting);
    int middle;
    if (n % 2 == 0 || n < 1)
    {
        return false;
    }
    if (n % 2 == 1)
    {
        middle = ((n + 1) / 2)-1;
    }
    int median = array[middle];
    return median;
}