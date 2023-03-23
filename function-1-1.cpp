#include <iostream>
using namespace std;

void printNumbers(int *array){
    for(int i = 0;i < 10;i++){
        cout << i << " " << array[i] << endl;
    }
}

int* readNumbers(){
    int *array = new int[10];
    for(int i = 0; i<10;i++){
        cout << "Enter a number: ";
        cin >> array[i];
        
    }
    printNumbers(array);
    return array;
}


