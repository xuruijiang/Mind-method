#include <stdio.h>
//3. 给定 M行N列的整数矩阵 data，如果 data
//的非边界元素 data［i][j］小于相邻的
//上下左右4个元素，那么就称元素 data［i][j］
//是矩阵的局部极小值。以下代码段已给出数组
//定义，请将主函数补充完整，实现如下功能：
//输入数组中各个元素的值，输出 data
//的全部局部极小值及其所在的位置。输出格式为
//每行按照 “元素值 行号 列号”的格式输出一个局部极
//小值，若没有局部极小值，则输出 “None”。

#define M 10
#define N 8
int main() {
    int data[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {

            scanf("%d",&data[i][j]);
        }//内for
    }//外for
    int choose = 0;
    for (int i = 1; i < M - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if(data[i][j] < data[i][j - 1]
            && data[i][j] < data[i][j + 1]
            && data[i][j] < data[i - 1][j]
            && data[i][j] < data[i + 1][j])
            {
                printf("%d  %d %d\n",data[i][j],i,j);
                choose = 1;
            }
        }
    }
    if(choose != 1)
    {
        printf("None");
    }
    return 0;
}
