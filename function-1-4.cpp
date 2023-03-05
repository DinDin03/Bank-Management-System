int sum_two_arrays(int array[], int secondarray[], int n){
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum1 = sum1 + array[i];
    sum2 = sum2 + secondarray[i];
  }
  int total = sum1+sum2;
  return total;

}