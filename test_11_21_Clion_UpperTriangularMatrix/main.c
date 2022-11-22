#include <stdio.h>
#include <stdlib.h>

int main() {

    int count = 0;
    int n = 0;
    scanf("%d",&n);
    int *p = (int *)malloc(sizeof(int) * (n * n));

    for (int i = 0; i < n * n; ++i) {
        scanf("%d",p+i);

    }


    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < i; ++j) {

            if(p[i * n + j] != 0){
                count = 1;
                break;
            }
        }
        if(count == 1){

            break;
        }
    }

    if(count == 1){

        printf("NO\n");
    } else{
        printf("YES\n");
    }
    return 0;
}
