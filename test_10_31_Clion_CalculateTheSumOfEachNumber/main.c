#include <stdio.h>


int fun(int num){

    if(num < 10){
        return num;
    }else{
        return (num % 10) + fun(num/10);
    }

}
int main() {


    int num = 0;
    scanf("%d",&num);
    printf("%d\n",fun(num)) ;
    return 0;
}
