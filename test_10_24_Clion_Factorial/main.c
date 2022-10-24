#include <stdio.h>

int main() {

    int sum = 0;
    int factorial = 1;


    for (int i = 0; i < 10; ++i) {

        for (int j = 1; j <= i; ++j) {

            factorial *= j;
        }

        sum += factorial;
        factorial= 1;
    }

    printf("%d\n",sum);
    return 0;
}
