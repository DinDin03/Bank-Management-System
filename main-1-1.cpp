#include <iostream>
using namespace std;
extern int array_sum(int[], int);

int main() {
    int array[5] = {4,5,6,7,8};
    std::cout << "The sum is: " << array_sum(array, 5) << std::endl;
    return 0;
}