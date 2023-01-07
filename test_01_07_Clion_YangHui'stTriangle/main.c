#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 0;
    printf("请输入输入多少行");
    scanf("%d",&n);

    //int* arr = (int *)malloc(sizeof(int) * n * n);

    int arr[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {

        arr[i][0] = 1;

    }



    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }

    }



    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n - i - 1; ++k) {
            printf(" ");
        }
        for (int j = 0; j <= i; ++j) {




            printf("%d ",arr[i][j]);

        }
        printf("\n");
    }
    return 0;
}
