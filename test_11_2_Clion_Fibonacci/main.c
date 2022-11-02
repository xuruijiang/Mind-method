#include <stdio.h>

int fibonacci(int num){

    if(num == 2 || num == 1){
        return 1;
    } else{
        return fibonacci( num - 2) + fibonacci(num - 1);
    }

}

int main() {

    int num = 0;
    scanf("%d",&num);

    printf("%d\n",fibonacci(num));
    return 0;
}
