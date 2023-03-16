#include <iostream>
using namespace std;

int sum_integers(int integers[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += integers[i];
  }
  cout << sum << endl;
  return sum;
}

int palindrome_sum(int integers[], int length){
    sum_integers(integers,length);
    return 0;

}

bool is_array_palindrome(int integers[], int length) {
  int palindrome = 0;
  for (int i = 0; i < length / 2 && length != 0; i++) {
    if (integers[i] != integers[length - i - 1]) {
      palindrome = 1;
      return -2;
      break;
    } else
      palindrome = 0;
      palindrome_sum(integers,length);
  }
  return 0;
}
