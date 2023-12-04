#include <stdio.h>
//1．编写程序计算以下求和式，n的值由键盘输入，
//以小数点后保留4位的形式输出s的值

//s = 1/1*2 + 1/2*3 + ...... + 1/n*(n + 1)
double f(int n)
{
    double s = 0;
    for (int i = 1; i <= n; ++i) {
        s = s + 1.0/(i * (i + 1));
    }
    return s;
}

int main() {
    int n = 0;
    scanf("%d",&n);
    double s = 0;
    s = f(n);
    printf("%.4lf",s);
    return 0;
}
