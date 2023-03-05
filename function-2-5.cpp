// checking if the numbers are in descending order or not
#include <iostream>

using namespace std;
bool is_descending(int array[], int n) {
  for (int i = 1; i < n; i++) {
    if (array[i - 1] < array[i]) {
      return false;
    }
  }

  return true;
}