#include <iostream>
using namespace std;

int is_identity(int array[10][10])
{
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == j)
            {
                sum += array[i][j];
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i != j)
            {
                sum2 += array[i][j];
            }
        }
    }
    if (sum == 10 && sum2 == 0)
    {
        std::cout << "Is identity" << std::endl;
        return 1;
    }
    std::cout << "Is not identity" << std::endl;
    return 0;
    
}