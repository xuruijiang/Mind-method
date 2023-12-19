#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//4. 编写一个函数，函数功能为判断一个整数是否为质数。
//并写出主函数，调用该函数，将10000之内的所有质数输出到屏幕，
//每行输出10个数据，并统计一共有多少个质数；并将这些质数依次
//写入一个文件中，文件名为zhishu.dat，文件中的格式与输出格式一致。

int Prime(int n)
{
    int temp = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0)
        {
            temp = 1;
            break;
        }

    }

    return temp;
}
int main() {

    FILE * fp = fopen("/Users/xuruijiang/Desktop/zhishu.txt","a");
    int number1 = 0;
    int number2 = 0;
    for (int i = 1; i < 10000; ++i) {

        if(!Prime(i))
        {
            printf("%d ",i);
            fprintf(fp,"%d ",i);
            number1++;
            number2++;
            if(number2 == 10)
            {
                fputc('\n',fp);
            }
        }
        if(number2 == 10)
        {
            printf("\n");
            number2 = 0;
        }
    }
    return 0;
}
