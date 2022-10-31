#include<stdio.h>
//条件二:x|y表示的是x整除y，y被x整除。
// 2|4，意思是4被2整除，即2整除4;
int divisible(long long a, long long b) {
    int flag = 1;
    if (b % a != 0)
    {
        flag = 0;
    }
    return flag;
}
//条件三，最大公约数
long long gcd(long long a, long long b) {
    if (a % b == 0)
        return b;
    else
        return (gcd(b, a % b));
}
//记录有多少组答案。
long long test(long long n) {
    long long count = 0;
    long long x, y, z;
    for (x = 1; x <= n; x++)
    {
        for (y = x; y <= n; y += x)
        {
            for (z = y; z <= n; z += y)
            {
                //满足第二个条件
                if (divisible(x, y) == 1 && divisible(y ,z) == 1) {

                    if (gcd(y/x,z/y) == 1 ) {
                        //满足三个条件就加1
                        count++;
                    }
                }

            }
        }
    }

//结果被998244353取模。
    printf("count = %d\n",count);
    return 998244353%count;
}
int main() {

//    int num = gcd(20,12);
//    printf("%d\n",num);
    long long n;
    scanf("%lld", &n);
    printf("%lld", test(n));
    return 0;
}