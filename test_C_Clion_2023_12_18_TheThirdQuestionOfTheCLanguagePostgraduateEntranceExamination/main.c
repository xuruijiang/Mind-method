#include <stdio.h>

//3. Fibonacci数列定义如下：第1，第2个数均为1，从第3个数开始，
//该数是其前面两个数之和。
//Fibonacci数列为：1，1，2，3，5，8，13，… 。
//编写递归函数，求Fibonacci数列的第n个数，
//并编写主函数，调用该递归函数，输出数列第60个数的值。

int Fibonacci(int n)
{
    if(n < 1)
    {
        printf("输入错误！\n");
    }
    else if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main() {

    int n = 0;
    printf("请输入斐波那契数: ");
    scanf("%d",&n);
    int sum = Fibonacci(n);
    printf("%d\n",sum);

    return 0;
}
