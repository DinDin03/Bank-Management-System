#include <iostream>
using namespace std;
extern bool median_array(int[], int, int);

int main() {
    int array[5] = {5,6,2,4,1};
    int w = sizeof(array) / sizeof(array[0]);
    std::cout << median_array(array, 5, w) << std::endl;
    return 0;
}