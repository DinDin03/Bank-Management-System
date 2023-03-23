using namespace std;
#include <iostream>

int *readNumbers() {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) {
    cout << "Enter a number: ";
    cin >> array[i];
  }
  return array;
}

int *reverseArray(int *array1,int length){
    int *array3 = new int[10];
    int index = 9;
    for(int i = 0; i<length; i++){
        array3[i] = array1[index];
        index--;
    }
    return array3;
}

bool equalsArray(int *array1, int *array3, int length) {
  int flag = 0;
  for (int i = 1; i < length; i++) {
    if (array1[i] != array3[i]) {
      flag++;
    }
  }
  if (flag == 0) {
    cout << "Yes" << endl;
    return true;
  } else
    cout << "No" << endl;
    return false;
}