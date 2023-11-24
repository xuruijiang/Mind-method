#include <stdio.h>

//2.写一个递归函数，函数名为f，功能为求正整数的位数，
//如f（12）的值2，f（589）的值为3，
//并写出调用该递归函数的语句，输出 12345678的位数。

int f(int n)
{
    if(n > 0)
    {
        return 1 + f(n/10);
    }//if
    else
    {
        return 0;
    }//else

}
int main() {

    int a = f(123456789);

    printf("%d\n",a);
    return 0;
}
