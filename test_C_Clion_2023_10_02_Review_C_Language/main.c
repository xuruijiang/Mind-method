#include <stdio.h>

//--------------------------------------------------//
int Fibonacci(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }//if
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }//else

}
//--------------------------------------------------//
int main() {
    int n = 0;
    int ret = 0;
    scanf("%d",&n);

    int i = 1;
    while(i <= n)
    {
        ret = Fibonacci(i);
        printf("%d，",ret);
        i++;
    }
    return 0;
}
//--------------------------------------------------//