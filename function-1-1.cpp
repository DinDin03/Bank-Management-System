#include <iostream> 

int size_of_variable_star_t(){
    int *t = new int;
    int s = sizeof(t);
    std::cout << s << std::endl;
    return s;
}

