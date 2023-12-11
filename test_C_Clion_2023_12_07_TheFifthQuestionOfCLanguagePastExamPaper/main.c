#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//5．编写一个函数，实现对一个整数加密处理，加密方法为：如果整数为
//负数，则加密之后结果为该数的绝对值；如果整数为非负数，加密方式
//将个位上的数字加6，如果超过10，则取个位上的数字。如-12，加密
//之后结果为12；356加密之后结果为352。函数名为fun_pass，参数
//及返回值请根据函数功能设计。编写主函数，实现如下功能：输入100
//个整数，调用函数fun_pass对这些数据进行加密处理，并将加密之后
//的数据，写入文件data.txt中。

void fun_pass(int * arr,int n)
{
    int sum = 0;
    int sign = 0;
    for (int i = 0; i < n; ++i) {
        if(arr[i]  >= 0 )
        {
            sign = arr[i] % 10;
            arr[i] = (arr[i]/10) * 10;
            sum = sign + 6;
            if(sign >= 10)
            {
                arr[i] = arr[i] + (sum % 10);
            }
            else
            {
                arr[i] = arr[i] + sum;
            }
        }
        else
        {
            arr[i] = -arr[i];
        }
        sum = 0;

    }

}
int main() {

    FILE *pf = fopen("/Users/xuruijiang/Downloads/data.txt","a");
    srand((unsigned ) time(NULL));
    int arr[100] = {0};

    for (int i = 0; i < 100; ++i) {
        arr[i] = rand()%1000;
    }
    for (int i = 0; i < 100; ++i) {
        printf("%4d ",arr[i]);
    }

    fun_pass(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n");
    for (int i = 0; i < 100; ++i) {
        fprintf(pf,"%d ",arr[i]);
        printf("%4d ",arr[i]);
    }

    fclose(pf);
    pf = NULL;
    return 0;
}
