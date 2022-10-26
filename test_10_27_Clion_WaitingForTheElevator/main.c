#include <stdio.h>

int main() {


    int n = 0;
    int time = 0;
    scanf("%d",&n);

    if((n + 1) % 12 == 0){
        time = (((n + 1) / 12) - 1) * 4 + 2;
    } else{
        time =  ((n + 1) / 12) * 4 + 2;
    }
    printf("%d\n",time);
    return 0;
}
