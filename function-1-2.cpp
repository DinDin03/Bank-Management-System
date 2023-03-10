#include <iostream>
using namespace std;

int is_identity(int array[10][10])
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[i][j] != 1 && array[j][i] != 0)
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
    {
        std::cout << "Is NOT identity" << std::endl;
        return 0;
    }
    std::cout << "Is identity" << std::endl;
    return 1;
}