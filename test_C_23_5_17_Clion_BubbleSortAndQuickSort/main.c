#include <stdio.h>

void swap(int * a,int * b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;

}

//-------------------------------------手动分割------------------------------------//
// 冒泡排序
void BubbleSort(int* a, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if(a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

            }//if
        }//内for
    }//外for

}
//-------------------------------------手动分割------------------------------------//
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
    int releft = left;
    int reright = right;
    int key = left;
    if(left == right)
    {
        return 0;
    }//if
    else
    {
        while(releft != reright)
        {
            while (reright > releft && a[reright] > a[key])
            {
                reright--;
            }
            while (releft < reright && a[releft] <= a[key])
            {
                releft++;
            }

            if(releft != reright)
            {

                swap(&a[releft],&a[reright]);
            }
            else
            {
                if(releft != key){
                    swap(&a[key],&a[releft]);
                }
            }


        }


    }//else



    if(releft > key)
    {
        PartSort1(a,0,releft - 1);
    }

    if(right > reright)
    {
        PartSort1(a + releft + 1, 0,right - releft - 1);
    }




    return 1;
}
//-------------------------------------手动分割------------------------------------//
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
//-------------------------------------手动分割------------------------------------//
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
//-------------------------------------手动分割------------------------------------//
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{


}

//-------------------------------------手动分割------------------------------------//
int main() {

    int a[17] = {3,6,9,2,4,7,8,1,5,0,3,5,6,97,12,4,5};
    PartSort1(a,0,16);
    for (int i = 0; i < 17; ++i) {
        printf("%d ",a[i]);
    }
    return 0;
}
