#include <stdio.h>

int main() {


    double n = 0;
    double sum = 0;
    scanf("%lf",&n);

    for (int i = 1; i <= n; ++i) {

        sum += (1.0)/((i)*(i + 1));
    }

    printf("%.4lf",sum);
    return 0;
}
