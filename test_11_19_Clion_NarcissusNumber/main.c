#include <stdio.h>
#include <math.h>

int fun(int num){

    int count = 0;

    while(num != 0){

        count++;
        num = num/10;
    }

    return count ;
}
int main() {


    int sum = 0;
    int num = 0;
    int count = 0;

    for (int i = 1; i < 100000; ++i) {

        count = fun(i);
        num = i;
        while(num != 0){
            sum += pow((num)%10, count);
            num = num/10;
        }

        if(sum == i){

            printf("%d ",i);
        }

        sum = 0;
    }
    return 0;
}
