#include <iostream>
using namespace std;
extern double sum_even(double[], int);

int main() {
    double array[5] = {4.1,5.1,6.1,7.1,8.1};
    std::cout << "The sum is: " << sum_even(array, 5) << std::endl;
    return 0;
}