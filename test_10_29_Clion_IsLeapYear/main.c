#include <stdio.h>

int is_leap_year(int n){

    if(n % 4 == 0 && n % 100 != 0 || n % 400 == 0){
        return 1;

    }else{
        return 0;

    }
}

int main() {

    int n = 0;
    scanf("%d",&n);

    if(is_leap_year(n)){
        printf("%d年是闰年\n",n);

    }else{
        printf("%d年不是闰年\n",n);

    }

    return 0;
}
