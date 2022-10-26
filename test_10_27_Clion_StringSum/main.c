#include <stdio.h>

int main() {


    long n = 0;
    scanf("%lld",&n);

    long long sum = (1 + n) * n / 2;
    printf("%lld\n",sum);
    return 0;
}
