#include <iostream>
using namespace std;
extern int array_mean(int[], int);

int main() {
    int array[5] = {4,5,6,7,8};
    std::cout << "The mean is: " << array_mean(array, 5) << std::endl;
    return 0;
}