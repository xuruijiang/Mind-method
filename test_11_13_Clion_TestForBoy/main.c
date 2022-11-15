#include <stdio.h>


void fun(int arr[5][5]){

    for (int i = 0; i < 9; ++i) {

        for (int j = 0; j < 9; ++j) {

            arr[i][j] = j;
        }
    }



}
int main() {


    int arr[9][9] = {0};



    fun(arr);


    //arr[0][18] = 10;
    for (int i = 0; i < 9; ++i) {

        for (int j = 0; j < 9; ++j) {

            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
