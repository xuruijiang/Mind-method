#include <stdio.h>

int main() {


    int sum = 0;
    int n = 0;
    scanf("%d",&n);

    sum = n * (2 + (2 + 3 * (n - 1)))/2;
    printf("%d",sum);
    return 0;
}
