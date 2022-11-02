#include <stdio.h>

int main() {

    int num = 0;
    scanf("%d",&num);

    int max = 1;
    int min = 1;
    int count = 0;

    for (int i = 1; i <= num; ++i) {

        if(num == 1 || num ==2){
            count = 1;
            break;
        } else{
            if(i >= 3){
                count = max + min;
                min = max;
                max = count;

            }

        }
    }

    printf("%d\n",count);
    return 0;
}
