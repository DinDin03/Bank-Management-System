bool is_fanarray(int array[], int n) {
  for (int i = 0; i < n / 2; i++) {
    if (array[i + 1] < array[i] || array[i] != array[n - i - 1]) {
      bool a = false;
    }
  }
  for (int i = n / 2; i < n - 1; i++) {
    if (array[i + 1] > array[i]) {
      bool b = false;
    }
  }
  if (bool b == true && bool a == true) {
    return true;
  } else {
    return false;
  }
}