#include <stdio.h>

int fun(int n,int k){
    if(k == 1){
        return n;
    } else{
        return n * fun(n,--k);
    }

}

int main() {


    int n = 0;
    int k = 0;
    scanf("%d%d",&n,&k);
    printf("%d\n", fun(n,k));

    return 0;
}
