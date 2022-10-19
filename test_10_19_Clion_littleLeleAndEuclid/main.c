#include <stdio.h>

int main() {


    unsigned long long num1 = 0;
    unsigned long long num2 = 0;

    unsigned long long comFactor = 0;
    unsigned long long comMultiple = 0;
    unsigned long long count = 0;

    scanf("%ld%ld", &num1, &num2);

    if (num1 == num2 ) {

        comFactor = num1;

    } else {

        count = (num1 > num2) ? num2 : num1;
        for (unsigned long long i = count , j = 2; i > 0; i = count / j , j++ ) {
            if (num1 % i == 0 && num2 % i == 0) {
                comFactor = i;
                break;
            }

        }
    }

    count = (num1 > num2) ? num1 : num2;

    if (count % num1 == 0 && count % num2 == 0) {

        comMultiple = count;
    } else {

        for (unsigned long long i = 2; ; ++i) {
            if (count * i % num1 == 0 && count * i % num2 == 0 ) {
                comMultiple = count * i;
                break;
            }

        }

    }

    printf("%ld\n", comMultiple + comFactor);

    return 0;
}
