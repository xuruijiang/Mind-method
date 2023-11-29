#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
//2. 编写一个函数 fun，函数的功能是：
//求出二维整型数组的最小元素及所在的行坐标、
//列坐标，（假设数组中元素无重复数据），
//函数参数及返回值自己设计。不允许使用全
//局变量。主函数中有如下定义：
//int data［5］I6］；且通过语句已经实现数组
//data 中30个数据的输入，请写出调用
//fun 函数，输出 data 数组中最小元素及
//所在的行坐标、列坐标。

void fun( int data[5][6])
{
    int min = data[0][0];
    int row = 0;
    int lin = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(min > data[i][j])
            {
                min = data[i][j];
                row = i;
                lin = j;
            }
        }
    }

    printf("%d %d %d\n",min,row,lin);
}
int main() {
    srand((unsigned)time(NULL));
    int data[5][6];
    //int row = sizeof(data)/sizeof(data[0]);
    //int lin = sizeof(data[0])/sizeof(data[0][0]);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            data[i][j] = rand()%1000;
            usleep(10000);
        }
    }

    for (int i = 0; i < 30; ++i) {
        printf("%d ",*(data[0] + i));
    }
    printf("\n");
    fun(data);
    return 0;
}
