#include <iostream>
using namespace std;
extern bool is_descending(int[], int);

int main() {
    int array[5] = {4,5,6,7,8};
    std::cout << is_descending(array, 5) << std::endl;
    return 0;
}