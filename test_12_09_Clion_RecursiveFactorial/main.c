#include <stdio.h>

double fun_pow(double x , int n){


    if(n > 1){
        return x * fun_pow(x,n -1);
    } else if(n == 1){
        return x;
    } else if(n == 0){
        return 1;
    }

}

int main() {

    double x = 2;
    double sum = 0;

    sum = fun_pow(x,10);
    printf("%lf\n",sum);


    return 0;
}
