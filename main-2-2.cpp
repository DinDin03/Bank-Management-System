#include <iostream>
using namespace std;

extern int bin_to_int(int[],int);

int main(){
    int binary[] = {1,1,0,1,0,0,1,1};
    int num = sizeof(binary)/sizeof(int);
    cout << bin_to_int(binary,num) << endl;
}