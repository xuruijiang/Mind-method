#include <stdio.h>
//--------------------------------------//
int binary_search(int * arr, int k, int count)
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

    }while(arr[mid] != k && left <= right);
    //while(arr[mid] != k)
    if(left > right)
    {
        return -1;
    }//if
    else
    {
        return mid;
    }

}
//--------------------------------------//
int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int index = binary_search(arr,8,sizeof arr/sizeof arr[0]);
    if(index != -1)
    {
        printf("%d\n",arr[index]);
    }//if
    else
    {
        printf("找不到\n");
    }//else
    return 0;
}
