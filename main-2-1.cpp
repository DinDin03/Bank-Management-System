#include <iostream>
#include <string>

extern float arithmetic_ops(float, float, std::string);

int main(){
    float left,right;
    char op[3];

    std::cout << "Enter the first number: ";
    std::cin >> left;
    std::cout << "Enter the operator(add/sub): ";
    std::cin >> op;
    std::cout << "Enter the second numbe: ";
    std::cin >> right;
    arithmetic_ops(left,right,op);
}