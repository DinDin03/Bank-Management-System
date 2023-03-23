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

bool equalsArray(int *array1, int *array2, int length) {
  int flag = 0;
  for (int i = 1; i < length; i++) {
    if (array1[i] != array2[i]) {
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
