#include <iostream>
using namespace std;

void arithmetic(int array[], int secondarray[])
{
    int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int carry[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 8; i++)
    {
        if (array[i] == 1 && secondarray[i] == 1)
        {
            result[i] = 0;
            carry[i + 1] = 1;
        }
        else
        {
            result[i] = array[i] + secondarray[i] + carry[i];
        }
        std::cout << result[i] << std::endl;
    }
}

int main()
{
    int array[8] = {0, 0, 0, 0, 0, 0, 0, 1};
    int secondarray[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    arithmetic(array, secondarray);
    return 0;
}