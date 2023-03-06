double array_mean(int array[], int n){
  int sum = 0;
  double average;
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }
  average = ((double(sum))/n);
  return average;
}