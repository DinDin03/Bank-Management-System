int min_element(int array[], int n){
    int i;
int min= array[0];
        for (i = 1; i < n; i++){
            if (array[i] < min)

{

min= array[i];

}}

return min;

}