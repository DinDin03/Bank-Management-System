#include <iostream>

extern int multiply_op(float, float);

int main(){
    float left, right;
    std::cout << "Enter the first number: ";
    std::cin >> left;
    std::cout << "Enter the second numbe: ";
    std::cin >> right;
    multiply_op(left,right);
}