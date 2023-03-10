#include <iostream>
#include <string>
using namespace std;

extern void print_binary_str(std::string);
int main(){
    char decimal_number[]= "104";
    print_binary_str(decimal_number);
    return 0;
}