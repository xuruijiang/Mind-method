#include <stdio.h>
#include <stdlib.h>

int main() {


    int N = 0;
    int M = 0;
    int sum = 0;

    scanf("%d%d",&N,&M);

    int *arr = (int *)malloc(sizeof(int) * 3 * 3 );


        for (int j = 0; j <N * M; ++j) {

            scanf("%d",&arr[j]);
        }



    for (int i = 0; i < N * M; ++i) {

        if(arr[i] >= 0){

            sum += arr[i];
        }
    }
    printf("%d\n",sum);

    free(arr);
    arr =NULL;
    return 0;
}
