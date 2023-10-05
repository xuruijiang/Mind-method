#include <stdio.h>
//----------------------------------------------//
void Sort(int arr[],int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = 1;
    }
}
//----------------------------------------------//
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Sort(arr,10);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%d\n",arr[i]);
    }

    return 0;
}
