#include <stdio.h>

int main() {
    long long numOne = 0;
    long long numTwo = 0;
    scanf("%lld%lld",&numOne,&numTwo);

    long long max = 0;
    long long min = 0;
    long long count = 0;
    max = (numOne > numTwo)? numOne:numTwo;
    min = (numOne < numTwo)? numOne:numTwo;

    long long multiple = 0;
    long long commonDivisor = 0;
    int temp = 1;

    while(temp){
        if(max % min == 0){
            commonDivisor = min;
            temp = 0;
        } else{
            count = max % min;
            max = min;
            min = count;
        }

    }

    multiple = numOne * numTwo / commonDivisor;
    printf("%lld\n",multiple + commonDivisor);


    return 0;
}
