#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 0;
    int m = 0;
    int count = 0;
    scanf("%d%d",&n,&m);

    int *pIntOne = (int *)malloc(sizeof(int) * n * m);
    int *pIntTwo = (int *)malloc(sizeof(int) * n * m);

    for (int i = 0; i < n * m; ++i) {

        scanf("%d",(pIntOne + i));
    }
    for (int j = 0; j < n * m; ++j) {

        scanf("%d",(pIntTwo + j));
    }

    for (int i = 0; i < n * m; ++i) {

        if(pIntOne[i] != pIntTwo[i]){

            count  = 1;
            break;
        }
    }

    if(1 == count){

        printf("No\n");
    } else{
        printf("Yes\n");
    }

    free(pIntOne);
    free(pIntTwo);
    pIntOne = NULL;
    pIntTwo = NULL;

    return 0;
}
