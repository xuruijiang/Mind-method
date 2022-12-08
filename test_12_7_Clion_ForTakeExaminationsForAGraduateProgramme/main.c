#include <stdio.h>

int main() {


    int a = 0;
    //a=a+2=3;
    double n = 0;
    double sum = 0;
    scanf("%lf",&n);

    for (int i = 1; i <= n; ++i) {

        sum += (1.0)/((i)*(i + 1));
    }

    printf("%.4lf",sum);
    return 0;
}
