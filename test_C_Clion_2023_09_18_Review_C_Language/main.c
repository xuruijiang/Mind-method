#include <stdio.h>
//-----------------------------------------------//
int greatestCommonDivisor(int num1, int num2)
{
    int large = (num1 > num2)? num1 : num2;
    int small = (num1 < num2)? num1 : num2;
    int k = 0;
    while((k = (large % small)))
    {
        large = small;
        small = k;
    }
    return small;
}
//-----------------------------------------------//
int main() {

    int CommonDivisor = greatestCommonDivisor(9,180);
    printf("%d\n",CommonDivisor);
    return 0;
}
