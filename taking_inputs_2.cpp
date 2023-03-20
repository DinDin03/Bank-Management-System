#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

void decimal_to_hexadecimal(int *ptr) {
  int decimal = *ptr;
  int decimal2 = decimal;
  int mod, count = 0;
  char hex[30];
  while (decimal2 > 0) {
    mod = decimal2 % 16;
    cout << "Current decimal: " << decimal2 << endl;
    cout << "Current mod: " << mod << endl;
    cout << "Current count: " << count << endl;
    if (mod >= 0 && mod <= 9) {
      hex[count] = mod;
    }
    else
    switch(mod){
      case 10:
        hex[count] = 'A';
        break;
      case 11:
        hex[count] = 'B';
        break;
      case 12:
        hex[count] = 'C';
        break;
      case 13:
        hex[count] = 'D';
        break;
      case 14:
        hex[count] = 'E';
        break;
      case 15:
        hex[count] = 'F';
        break;
    }
    count++;
    decimal2 = decimal2 / 16;
    
  }
  cout << "The Hexadecimal representation of the binary number you entered is: ";
  for (int i = count-1; i>=0; i--) {
    cout << hex[i];
  }
  cout  << endl;
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
  decimal_to_hexadecimal(ptr);
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
  // binary_to_hexadecimal(decimal, binary);
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