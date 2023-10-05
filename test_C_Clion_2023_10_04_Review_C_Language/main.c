#include <stdio.h>
//---------------------------------------------------//
int main() {

    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0][0]); ++i) {
        printf("%d,",*(arr[0] + i));
    }//for

    //printf("%d\n",arr[0][10]);//居然可以
//    int *p = arr[0];
//    int *p1 = (int *)arr;
//    printf("%d\n",*(p + 1));
//    printf("%d\n",*(p1 + 2));
    //printf("%d\n",);
    return 0;
}
//---------------------------------------------------//