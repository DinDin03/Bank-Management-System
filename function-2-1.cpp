#include <iostream>
#include <string> 

float add_op(float left, float right){
    float sum = left + right;
    return sum;
}
float substract_op(float left, float right){
    float sum = left - right;
    return sum;
}
float arithmetic_ops(float left, float right, std::string op){
    if(op == "add"){
        add_op(left,right);
    }
    if(op == "sub"){
        substract_op(left,right);
    }
    else 
        std::cout << "INVALID" << std::endl;
    return 0;
}