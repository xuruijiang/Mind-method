#include <stdio.h>
//--------------------------------------//
int binary_search(int *arr, int k, int count)
{
    int left = 0;
    int right = count - 1;
    int mid = 0;
    do {
        mid = (left + right)/2;
        if(arr[mid] > k)
        {
            right = mid - 1;
        }//if
        else if(arr[mid < k])
        {
            left = mid + 1;
        }//else if

    }while(arr[mid] != k);
    //while(arr[mid] != k)
    return mid;
}
//--------------------------------------//
int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int index = binary_search(arr,2,10);
    printf("%d",arr[index]);
    return 0;
}
