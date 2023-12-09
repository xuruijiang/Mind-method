#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//4．编写一个函数，功能为求出整型数组中数据的最大值、最小值，要求
//：函数名为fun_array，数组大小由参数确定，
//其余参数以及函数返回值等请根据函数功能设计。
//并将以下主函数补充完整，调用函数fun_array，
//输出数组的最大值，最小值。(主函数中若需要增加变量，请自行定义声明)
//#include <stdio.h>
//int main()
//{
//    int data[20],i;
//    for (i=0; i<20; i++)
//        scanf("%d",data+i);
//    ……
//}
void fun_array(int * data, int n)
{
    int min = data[0];
    int max = data[0];
    for (int i = 1; i < n; ++i) {
        if(data[i] < min)
        {
            min = data[i];
        }
        else if(data[i] > max)
        {
            max = data[i];
        }
    }

    printf("min: %d, max: %d",min, max);
}

int main() {
    srand((unsigned)time(NULL));
    int data[20],i;
    for (i=0; i<20; i++)
    {
        //scanf("%d",data+i);
        data[i] = rand()%200;
    }

    for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        printf("%d ",data[i]);
    }
    printf("\n");
    fun_array(data,sizeof(data)/sizeof(data[0]));

    return 0;
}
