#include <stdio.h>

//--------------------------------------------------//
int FibonacciRecursion(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }//if
    else
    {
        return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
    }//else

}
//--------------------------------------------------//
long long FibonacciIteration(int n)
{
    long long Fib1 = 1;
    long long Fib2 = 1;
    if(n == 1 || n == 2)
    {
        return 1;
    }//
    else
    {
        long long temp = 0;
        for (int i = 3; i <= n ; ++i) {
            temp = Fib2;
            Fib2 = Fib1 + Fib2;
            Fib1 = temp;
        }
        return Fib2;
    }//else

}
//--------------------------------------------------//
int main() {
    int n = 0;
    long long ret = 0;
    scanf("%d",&n);

    int i = 1;
    while(i <= n)
    {
        //ret = FibonacciRecursion(i);
        ret = FibonacciIteration(i);
        printf("%lld，",ret);
        i++;
    }
    return 0;
}
//--------------------------------------------------//