#include <iostream>
using namespace std;

extern bool sum_if_palindrome(int[], int);
int main() {
    int arr1[] = {1, 2, 3, 4, 3, 2, 1};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int arr3[] = {};
    int arr4[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    cout << "arr1 sum: " << sum_if_palindrome(arr1, 7) << endl; // prints "arr1 sum: 16"
    cout << "arr2 sum: " << sum_if_palindrome(arr2, 6) << endl; // prints "arr2 sum: -2"
    cout << "arr3 sum: " << sum_if_palindrome(arr3, 0) << endl; // prints "arr3 sum: -1"
    cout << "arr4 sum: " << sum_if_palindrome(arr4, 9) << endl; // prints "arr4 sum: 20"

    return 0;
}