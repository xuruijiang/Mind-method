#include <stdio.h>

int stepPlus(int n ){

    int sum = 0;
    for (int i = 1; i <= n ; ++i) {
        sum += i;
    }
    return sum;
}
int main() {

    int n = 0;
    scanf("%d",&n);
    int max = stepPlus(n);
    int min = stepPlus(n - 1);

    for (int i = 0,j = 1; i < max; ++i,j = j + 2) {

        if(i >= min){

            printf("%d",j);
        }

        if(i < max - 1 && i >= min){
            printf("+");

        }

    }

    return 0;
}
