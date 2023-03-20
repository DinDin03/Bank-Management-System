#include <math.h>
#include <iostream>
using namespace std;

void decimal_to_hexadecimal(int *ptr){
    int decimal = *ptr;
    int rem = decimal/16;
    int mod;
    for(int i = 0;i<rem;i++){
      mod = decimal%16;
    }
    
}

int binary_to_decimal(int num, int binary[]) {
  int index = 0, decimal = 0, *ptr;
  for (int i = num - 1; i >= 0; i--) {
    decimal += binary[i] * pow(2, index);
    index++;
  }
  ptr = &decimal;
  cout << "The decimal representation of the binary number is: " << decimal
       << endl;
  check(ptr);
  return *ptr;
}

int userinput(int num) {
  int binary[num];
  int digit;
  for (int i = 0; i < num; i++) {
    cout << "Enter the digit: ";
    cin >> digit;
    if (digit != 1 && digit != 0) {
      while (digit != 0 && digit != 1) {
        cout << "Invalid number. Enter the digit: ";
        cin >> digit;
        binary[i] = digit;
      }
    } else
      binary[i] = digit;
  }
  cout << "The binary number you entered was: ";
  for (int i = 0; i < num; i++) {
    cout << binary[i];
  }
  cout << endl;
  binary_to_decimal(num, binary);
  //binary_to_hexadecimal(decimal, binary);
  return *binary;
}

int main() {
  int num;
  cout << "How many binary digits are there: ";
  cin >> num;
  if (num <= 0) {
    while (num <= 0) {
      cout << "Invalid number. Enter again: ";
      cin >> num;
    }
  }
  userinput(num);
}