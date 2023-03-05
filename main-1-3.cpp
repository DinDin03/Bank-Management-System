#include <iostream>
using namespace std;
extern int num_count(int[], int, int);

int main() {
    int array[5] = {7,5,6,7,8};
    std::cout << "The count is: " << num_count(array, 5, 7) << std::endl;
    return 0;
}