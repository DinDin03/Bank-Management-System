using namespace std;
#include <iostream>

extern int readNumbers();
extern bool equalsArray(int[], int[], int);

int main() {
  int *array1 = new int[10];
  int *array2 = new int[10];

  cout << "For the first array: " << endl;
  *array1 = readNumbers();

  cout << "For the second array: " << endl;
  *array2 = readNumbers();

  equalsArray(array1, array2, 10);
  return 0;
}