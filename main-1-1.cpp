extern void print_matrix(int[10][10]);

int main(){
    int array[10][10] = {};
    int num = 0;
    for(int i =0;i<10;i++){
        for(int j = 0;j<10;j++){
            array[i][j] = num;
            num++;
        }
    }
    print_matrix(array);
}