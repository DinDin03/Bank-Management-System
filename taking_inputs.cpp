#include <iostream>
using namespace std;

void userinput(int n) {
  int array[n] = {};
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int s;
    std::cout << "Enter a number: ";
    std::cin >> s;
    std::cout << "The number you entered was: " << s << std::endl;
    array[i] = s;
  }
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }
  std::cout << "The sum of the values you entered is: " << sum << std::endl;
}

int main() {
  int n = 5;
  userinput(n);
  return 0;
}