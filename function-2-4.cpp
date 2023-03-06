bool is_ascending(int array[], int n){
    int count = 0;
    for(int i = 0;i < n; i++){
        if(array[i] <= array[i+1]){
            count++;
        }
    }
    if(count == n){
        return true;
    }
    else if (count != n || n < 1){
        return false;
    }
    return 0;
}