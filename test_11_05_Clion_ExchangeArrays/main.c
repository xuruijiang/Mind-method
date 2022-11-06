#include <stdio.h>

void Exchange(int *ptr1 ,int *ptr2 ,int n){

    for (int i = 0; i < n; ++i) {

        ptr1[i] = ptr1[i] ^ ptr2[i];
        ptr2[i] = ptr1[i] ^ ptr2[i];
        ptr1[i] = ptr1[i] ^ ptr2[i];
    }

}
int main() {


    int arr1[10] = {10,9,8,7,6,5,4,3,2,1 };
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10 };
    Exchange(arr1,arr2,(sizeof(arr1)/sizeof(int)));

    for (int i = 0; i < (sizeof(arr1)/sizeof(int)); ++i) {

        printf("arr1[%d] = %d,arr2[%d] = %d\n",i,arr1[i],i,arr2[i]);
    }

    return 0;
}
