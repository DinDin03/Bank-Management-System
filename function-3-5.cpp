double sum_even(double array[], int n) {
  double sum = 0;
  for (int i = 0; i < n; i+=2) {
    sum = sum + array[i];
  }
  return sum;
}