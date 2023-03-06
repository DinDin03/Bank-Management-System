#include <iostream>
using namespace std;
extern bool weighted_average(int[], int);

int main() {
    int array[5] = {1,2,1,4,1};
    std::cout << weighted_average(array, 5) << std::endl;
    return 0;
}