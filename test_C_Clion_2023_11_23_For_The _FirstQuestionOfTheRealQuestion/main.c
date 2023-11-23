#include <stdio.h>

int main() {

    double e = 1;
    double pet = 1.0;
    int j = 1;
    while (pet > 0.000001)
    {
        pet = 1.0;
        for (int i = 1; i <= j; ++i) {
            pet /= i;
        }
        j++;
        e += pet;
    }
    printf("%lf\n",e);
    return 0;
}
