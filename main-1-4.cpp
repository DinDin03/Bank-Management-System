extern int print_scaled(int[3][3], int scale);

int main(){
    int array[3][3] = {1,2,3,4,5,6,7,8,9};
    int scale = 3;
    print_scaled(array, scale);
    return 0;
}