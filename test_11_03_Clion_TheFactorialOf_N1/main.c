#include <stdio.h>

int main() {

    int n = 0;

    scanf("%d",&n);
    int factorial= 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;

    }
    printf("%d\n",factorial);
    return 0;
}

