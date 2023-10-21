#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);

//--------------------------------------------------//
void printf_arr(int arr[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%-3d ",arr[i][j]);
        }
        printf("\n");
    }

}
//--------------------------------------------------//
int* search(int arr[ROW][COL],int row, int col, int count) {
    if(arr[0][0] > count)
    {
        return NULL;
    }//if
    int ar[2] = {0};
    int knot = 0;
    int knot2 = 0;
    int choose = 0;
    int *index = malloc(sizeof(int) * 2);
    for (int i = row - 1; i >= 0; --i) {
        if(arr[i][0] <= count)
        {
            knot = i;
            break;
        }//if
    }//for
    for (int i = 1; i < col; ++i) {
        if(arr[knot][i] == count)
        {
            choose = 1;
            index[0] = knot;
            index[1] = i;
            return index;
        }//if
        else
        {
            if(arr[knot][i] >= count)
            {
                knot2 = i;
                break;
            }
        }//else
    }//for

    for (int i = 1; i < row; ++i) {
        if(arr[knot][knot2] == count)
        {
            choose = 1;
            index[0] = knot;
            index[1] = knot;
            return index;
        }//if
        else
        {
            if(arr[knot - i][knot2] == count)
            {
                choose = 1;
                index[0] = knot - i;
                index[1] = knot2;
                return index;
            }
        }//else
    }//if
    free(index);
    index = NULL;
    return NULL;
}
//--------------------------------------------------//
int main() {

    int arr[ROW][COL] = {0};
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            arr[i][j] = i + 1 + 2 * j;
        }//内循环

    }//外循环
    printf_arr(arr,ROW,COL);

    int count = 0;
    scanf("%d",&count);
    int * index = search(arr,ROW,COL,count);
    if(index == NULL)
    {
        printf("没有找到\n");
    }
    else
    {
        printf("找到了！！！坐标为: arr[%d][%d]\n",*index,*(index + 1));
        free(index);
        index = NULL;
    }

    return 0;
}
