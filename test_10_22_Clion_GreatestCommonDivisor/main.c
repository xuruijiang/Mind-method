#include <stdio.h>

int main() {



    int num1 = 0;
    int num2 = 0;

    scanf("%d %d",&num1, &num2);

    int min = (num1 > num2)? num2 : num1;

    int big = 1;
    for (int i = 2; i <= min; ++i) {

        if(num1 % i == 0 && num2 % i == 0){
            big = i;
        }
    }
    printf("%d\n",big);

    return 0;
}
