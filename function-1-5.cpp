#include <iostream>
using namespace std;

void print_summed(int array[3][3], int array2[3][3])
{
    int array3[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array3[i][j] = array[i][j] + array2[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << array3[i][j] << " ";
        }
        std::cout << "\n";
    }
}