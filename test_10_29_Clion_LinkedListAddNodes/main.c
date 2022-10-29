#include <stdio.h>
#include <stdlib.h>

struct linkNum{
    int num;
    struct linkNum *p;
};

struct linkNum * fun( int *p, int n,int coordinate){

    struct linkNum *ptr = (struct linkNum *)malloc(sizeof(struct linkNum) * (n+1));

    struct linkNum *ptrOne = ptr;
    struct linkNum *ptrTwo = ptr;

    for (int i = 0; i < n + 1; ++i) {

        if ( i == coordinate){
            ptrOne->num = i;
            if (n  == i){
                ptrOne->p = NULL;
                break;
            }
            ptrOne->p = ++ptrTwo;
            ptrOne = ptrOne->p;

            continue;
        }
        ptrOne->num = *p;

        if (n  == i){
            ptrOne->p = NULL;
            break;

        }
        p++;
        ptrOne->p = ++ptrTwo;
        ptrOne = ptrOne->p;
    }

    return ptr;


}

int main() {

    int n = 0;
    int coordinate = 0;
    scanf("%d%d",&n,&coordinate);
    int arr[10000];

    for (int i = 0; i < n; ++i) {

        scanf("%d",&arr[i]);
    }

    struct linkNum *ptr = fun(arr,n,coordinate);

    for (int i = 0; i < n + 1; ++i) {

        printf("%d ",ptr->num);
        ptr = ptr->p;

    }
    return 0;
}
