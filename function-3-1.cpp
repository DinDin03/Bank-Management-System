bool is_fanarray(int array[], int n) {
  if(n < 1){
    return false;
  }
  int count = 0;
  int middle;
  if(n%2==0){
    middle = n/2;
  }
  else middle = (n+1)/2;

  for (int i = 0; i < n; i++) {
    if(array[i] == array[n-1-i]){
      count++;
    }
  }
  if(count == n){
    return true;
  }
  return false;
}