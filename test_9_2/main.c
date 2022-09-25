#include <stdio.h>

int main() {


    int R[10] = {1,2,3,4,5,6,7,8,9,10};

    int arr[10] = {0};

    for (int i = 0; i < 10; ++i) {

        arr[i] = R[i];
    }

    int p = 0;
    printf("输入一个p 0<p<10懂得都懂:");
    scanf("%d",&p);
    int one = 0;

    for (int i = 0; i < 10; ++i) {
        if(p<10){
            R[i] = arr[p];
            p++;
        }else{
            R[i] = arr[one++];
        }


    }

    for (int i = 0; i < 10; ++i) {

        printf("%d,",R[i]);
    }

}
