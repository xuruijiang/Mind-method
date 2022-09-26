#include <stdio.h>


int gcd(int a, int b ) {
    // write code here

    int big =  (a>b)? a:b;
    int litter = (a<b)? a:b;
    int s = 0;
    while (s = big % litter){
        big = litter;
        litter = s;
    }

    return litter;

}
int main() {


    int a = 100;
    int b = 150;
    int z = 9;

    //a = b == z;
    printf("%d",gcd(a,b));
    return 0;
}
