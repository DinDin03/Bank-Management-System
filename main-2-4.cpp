#include <iostream>
using namespace std;
extern bool is_ascending(int[], int);

int main() {
    int array[5] = {9,5,6,7,8};
    std::cout << is_ascending(array, 5) << std::endl;
    return 0;
}