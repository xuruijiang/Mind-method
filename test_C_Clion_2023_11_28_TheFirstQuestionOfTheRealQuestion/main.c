#include <stdio.h>
//1. 自守数是指其平方数的低位部分恰为该数本身的
//自然数，如52=25，则5为自守数。十进制中0、
//1、5、6、25、76、376等均自守数，请编写程序，
//输出1000之内的自守数。

int NumberOfDigit(int x)
{
    if(x == 0)
    {
        return 0;
    }
    else
    {
        return 1 + NumberOfDigit(x/10);
    }

}

int main() {

    for (int i = 0; i < 1000 ; ++i) {
        if(NumberOfDigit(i) == 0)
        {
            printf("%d ",i);
        }
        else if(NumberOfDigit(i) == 1)
        {
            if(i == i*i%10)
            {
                printf("%d ",i);
            }
        }
        else if(NumberOfDigit(i) == 2)
        {
            if(i == i*i%100)
            {
                printf("%d ",i);
            }
        }
        else if(NumberOfDigit(i) == 3)
        {
            if(i == i*i%1000)
            {
                printf("%d ",i);
            }
        }
    }

    return 0;
}
