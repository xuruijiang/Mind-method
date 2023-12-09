#include <stdio.h>
#include <assert.h>
//3．给定如下函数声明，double fun_pow(double x,int n)；
//该函数的返回值为x的n次方，并且该函数是一个递归函数。请将函数体补
//充完整，并写出主函数，调用函数fun_pow，求出2的10次方，并输出。
//]（说明：本题不允许使用math.h中的函数pow）

double fun_pow(double x,int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return x;
    }
    else if(n < 0)
    {
        return 1 * 1/x * fun_pow(x,n + 1);
    }
    else
    {
        return x * fun_pow(x,n - 1);
    }


}
int main() {

    double x = 0;
    int n = 0;
    scanf("%lf",&x);
    scanf("%d",&n);
    printf("%.20lf",fun_pow(x,n));
    return 0;
}
