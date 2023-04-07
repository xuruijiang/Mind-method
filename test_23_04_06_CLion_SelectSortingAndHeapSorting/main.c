#include <stdio.h>

//-----------------------------------------------手动分割------------------------------------------------------//
// 选择排序
void swap(int * a, int * b)
{
    int temp = *a;

    *a = *b;
    *b = temp;

}//函数结束

void SelectSort(int* a, int n)
{
    int min = 0;
    int max = 0;
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        for (int i = left; i <= right; ++i) {
            if(a[i] > a[max])
            {
                max = i;
            }//if

            if(a[i] < a[min])
            {
               min = i;
            }//if
        }//for

        if(max == left)
        {
            max = min;
        }//if

        swap(a + left , a + min);
        swap(a + right, a + max);

        left++;
        right--;
        min = left;
        max = left;

    }//while结束


}//函数结束

//-----------------------------------------------手动分割------------------------------------------------------//
// 堆排序
void AdjustDwon(int* a, int n, int root)
{
    int parent = root;

    int child = parent * 2 + 1;

    while (child < n - 1)
    {
       if(child + 1 < n - 1)
       {
           if(a[child] > a[child + 1])
           {
               child++;
           }//if

       }//if

       if(a[parent] > a[child])
       {
           swap(a + parent, a + child);
       }//if

       parent = child;
       child = parent * 2 + 1;

    }//while


}//函数结束

void JustDown(int *a , int size)
{
    //printf("%d  ",*a);
    swap(a,a + size - 1);

    int parent = 0;
    int child = parent * 2 + 1;

    while (child < size - 2)
    {
        if(child + 1 < size - 2)
        {
            if(a[child] > a[child + 1])
            {
                child++;
            }//if

        }//if

        if(a[parent] > a[child])
        {
            swap(a + parent, a + child);
        }//if

        parent = child;
        child = parent * 2 + 1;

    }//while

}//函数结束

void HeapSort(int* a, int n)
{
    for (int i = 0; i < n; ++i) {
        JustDown(a,n - i);
    }//for

}//函数结束
//-----------------------------------------------手动分割------------------------------------------------------//

int main() {

    int arr[20] = {6,4,8,1,9,0,2,3,55,32,12,677,43,878,4,23,89,43,2323,55};
    SelectSort(arr,sizeof(arr)/sizeof(int) );

    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
        printf("%d  ",arr[i]);
    }

    printf("\n");

    int arr1[20] = {6,4,8,1,9,0,2,3,55,32,12,677,43,878,4,23,89,43,2323,55};

    for (int i = sizeof(arr1)/sizeof(int); i >= 0 ; --i) {

        AdjustDwon(arr1,sizeof(arr1)/sizeof(int),i);
    }

    HeapSort(arr1,sizeof(arr1)/sizeof(int));

    for (int i = 0; i < sizeof(arr1)/sizeof(int); ++i) {
        printf("%d  ",arr1[sizeof(arr1)/sizeof(int) - 1 - i]);
    }
    return 0;
}
