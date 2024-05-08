#include <stdio.h>

float fac_recursion(int n)
{
    /**********  Begin  **********/

    int sum = 0;
    if(n == 1)
    {
        return 1;
    }
    if(n > 1)
    {
        sum = n * fac_recursion(n - 1);
    }
    return sum;

    /**********  End  **********/
}
int main() {

    int n = 0;
    scanf("%d",&n);
    printf("%f ", fac_recursion(n));
    return 0;
}
