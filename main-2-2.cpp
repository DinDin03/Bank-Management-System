#include <iostream>
using namespace std;
extern int max_element(int[], int);

int main() {
    int array[5] = {4,5,6,7,8};
    std::cout << "The maximum is: " << max_element(array, 5) << std::endl;
    return 0;
}