#include <stdio.h>


// 插入排序
void InsertSort(int* a, int n)
{
    int temp = 0;


    for (int i = 0; i < n; ++i) {

        for (int j = i; j > 0 ; --j) {

            if(a[j] < a[j - 1])
            {
                temp = a[j];
                a[j]= a[j - 1];
                a[j - 1] = temp;
            }//if
            else
            {
                break;
            }//braek

        }//内for
    }//外for

}//函数结束

// 希尔排序
void ShellSort(int* a, int n)
{
    int gap = n/2;
    int temp;

    int m = gap;
    int num = 0;
    while (gap)
    {

        for (int i = 0; i  < gap; ++i)
        {


            for (int j = i; j  < n; j = j + gap)
            {

                for (int k = j; k  > i ; k = k - gap)
                {

                    if(a[k] < a[k - gap])
                    {
                        num++;
                        if(m != gap)
                        {
                            printf("%d\n",num);
                            num = 0;
                            m = gap;

                        }//if 试试每次gap 换过多少次
                        temp = a[k];
                        a[k]= a[k - gap];
                        a[k - gap] = temp;
                    }//if
                    else
                    {
                        break;
                    }//braek

                }//内for
            }//外for

        }//for

        gap = gap/2;
    }//while

    printf("%d\n",num);

}//函数结束



int main() {

    int arr1[10] = {3,5,8,1,88,44,3,72,7,2};
    int arr2[60] = {3,8,6,3,9,1,34,65,88,12,34,8,76,234,67,131,
                    66,21,44,0,5,75,55,23,6,43,66,66,3,23,55
    ,45,2323,5456,323,678,568,22,0,7,4,2,6,8,43,13,7,34,23,42,34,45,77,234,4577,33,23
    ,3,4,7};

    InsertSort(arr1,sizeof(arr1)/4);
    ShellSort(arr2,sizeof(arr2)/4);
    for (int i = 0; i < sizeof(arr1)/4 ; ++i) {

        printf("%d ",arr1[i]);
    }//for

    printf("\n");
    for (int i = 0; i < sizeof(arr2)/4; ++i) {
        printf("%d ",arr2[i]);
    }

    return 0;
}
