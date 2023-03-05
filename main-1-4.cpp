#include <iostream>
using namespace std;
extern int sum_two_arrays(int[], int[], int);

int main() {
    int array[5] = {7,5,6,7,8};
    int secondarray[5] = {1,2,3,4,5};
    std::cout << "The count is: " << sum_two_arrays(array,secondarray,5) << std::endl;
    return 0;
}