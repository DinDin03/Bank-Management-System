#include <iostream>
using namespace std;
extern bool is_fanarray(int[], int);

int main() {
    int array[5] = {1,2,3,2,1};
    std::cout << is_fanarray(array, 5) << std::endl;
    return 0;
}