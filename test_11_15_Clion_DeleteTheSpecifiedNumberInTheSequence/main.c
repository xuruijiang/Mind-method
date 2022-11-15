#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 0;
    scanf("%d",&n);
    int *p = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {

        scanf("%d",p + i);
    }
    int num = 0;
    scanf("%d",&num);
    int count = 0;

    for (int i = 0; i < n; ++i) {

        if( p[i] == num ){
            count++;
            for (int j = i; j < n - 1; ++j) {

                p[j] = p[j] ^ p[j+1];
                p[j+1] = p[j] ^ p[j+1];
                p[j] = p[j] ^ p[j+1];
            }
            n--;
            i--;
        }

    }

    for (int i = 0; i < n  ; ++i) {

        printf("%d ",p[i]);
    }

    free(p);
    p = NULL;

    return 0;
}
