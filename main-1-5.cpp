#include <iostream>
using namespace std;
extern int count_evens(int);

int main() {
    int num = 100;
    std::cout << "The count is: " << count_evens(num) << std::endl;
    return 0;
}