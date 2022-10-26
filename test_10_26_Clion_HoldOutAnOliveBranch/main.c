#include <stdio.h>


long long and(int n){

    if(n == 1){
        return 1;
    } else{

        return n + and(n - 1);
    }

}
int main() {

    int n = 0;
    scanf("%d",&n);
    long long sum =  and(n);
    printf("%lld\n",sum);

    return 0;
}
//o容易栈溢出