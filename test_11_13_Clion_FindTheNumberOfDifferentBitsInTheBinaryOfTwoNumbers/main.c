#include <stdio.h>


int fun(int num1, int num2){
    
    int count = 0;

    for (int i = 0; i < 32; ++i) {

        if((num1 & 1) != (num2 & 1)){

            count++;
        }

        num1 = num1>>1;
        num2 = num2>>1;

    }

    return count;

    
}
int main() {
   
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d",&num1,&num2);

    int number = fun(num1,num2);

    printf("%d\n",number);
    
    return 0;
}
