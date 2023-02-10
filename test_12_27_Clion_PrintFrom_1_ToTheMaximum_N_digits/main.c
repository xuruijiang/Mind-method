#include <stdio.h>

//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//1. 用返回一个整数列表来代替打印
//2. n 为正整数，0 < n <= 5

int* printNumbers(int n, int* returnSize ) {
    // write code here

    int m = 9;
    for(int i = 1;i < n; i++){

        m = m *10 + 9;
    }
    //returnSize = (int *) malloc(m * 4);

    for(int j = 0; j < m ; j++){

        *(returnSize + j) = j + 1;

        printf("%d,",*(returnSize + j));
    }

    return returnSize;
}

int main() {

    int n = 3;

    int arr[1000] = {0};

    printNumbers(n,arr);


    return 0;
}
