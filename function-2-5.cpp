bool is_descending(int array[], int n){
    int count = 0;
    for(int i = 0;i < n; i++){
        if(array[i] >= array[i+1]){
            count++;
        }
    }
    if(count == n){
        return true;
    }
    return false;
}