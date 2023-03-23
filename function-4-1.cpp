#include <iostream>
using namespace std;

void printNumbers(int *array){
    for(int i = 0;i < 4;i++){
        cout << i << " " << array[i] << endl;
    }
}

int* readNumbers(){
    int *array = new int[10];
    for(int i = 0; i<4;i++){
        cout << "Enter a number: ";
        cin >> array[i];
        
    }
    printNumbers(array);
    return array;
}

int secondSmallestSum(int *array,int length){
    int size = length*(length+1)/2;
    int  *sum = int new[size];
    for(int i = 0; i < length;i++){
        

    }

}

