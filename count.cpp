int count(int array[], int n) {
  int even = 00;

  for (int i = 0; i < n; i++) {
    if (array[i] % 2 == 0) {
      even++;
    }
  }
  return even;
}