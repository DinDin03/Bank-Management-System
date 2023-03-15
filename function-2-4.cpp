#include <iostream> 

float arithmetic_ops(float left, float right, float (*op)(float,float))
{
return (*op)(left, right);
}
float multiply_op(float left, float right){
    float sum = left*right;
    std::cout << sum << std::endl;
    return sum;
}