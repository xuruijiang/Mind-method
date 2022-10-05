#include <stdio.h>


//然而这种解法效率低，对于斐波那契数有更好解法。
int climbStairs(int n){
    if( n == 1){
        return 1;
    } else if( n == 2){
        return 2;
    }
    int a = 1;
    int b = 2;
    int temp;

    for (int i = 3; i <=n; ++i) {

        temp = a;
        a = b ;
        b = temp + b;

    }

    return b;

}
int main() {


    int n = 45;

    int sum = climbStairs( n );

    printf("有%d种爬法\n",sum);
    return 0;
}
