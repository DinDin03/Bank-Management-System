using namespace std; 
#include <iostream> 

void hexDigits(int *array, int length){
    for(int i = 0; i < length; i++){
        if(array[i]>=0 && array[i] <= 9){
            cout << i << " " << array[i] << endl;
        }
        else
            switch(array[i]){
                case 10:
                   cout << i << " " << 'A' << endl; 
                   break;
                case 11:
                   cout << i << " " << 'B' << endl;
                   break;
                case 12:
                   cout << i << " " << 'C' << endl;
                   break;
                case 13:
                   cout << i << " " << 'D' << endl;
                   break;
                case 14:
                   cout << i << " " << 'E' << endl;
                   break;
                case 15:
                   cout << i << " " << 'F' << endl;
                   break;
            }
    }
}

int* readNumbers(){
    int *array = new int[10];
    for(int i = 0; i<10;i++){
        cout << "Enter a number: ";
        cin >> array[i];        
    }
    hexDigits(array,10);
    return array;
}