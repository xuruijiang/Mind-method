#include <stdio.h>
#include <math.h>
//---------------------------------------------//
void PrimeNumber(int min, int max)
{
    int tmp = 0;
    for (int i = min; i <= max; ++i) {
        for (int j = 2; j <= sqrt(i); ++j) {
            if(i % j == 0)
            {
                tmp = 1;
                break;
            }
        }//内循环//---------------------------------------------//
        if(tmp == 0)
        {
            printf("%d,",i);
        }
        tmp = 0;
    }//外循环
    printf("\n");
}
//---------------------------------------------//
int main() {

    PrimeNumber(1,1000333);
    return 0;
}
//---------------------------------------------//