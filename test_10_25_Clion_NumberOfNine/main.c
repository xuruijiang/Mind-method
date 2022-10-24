#include <stdio.h>

int main() {

    int count = 0;
    int ret = 0;
    for (int i = 1; i < 100; ++i) {
        count = i;
        if(count % 10 == 9){
            ret++;
        }
        count = count / 10;
        if(count != 0 && count % 10 == 9){
            ret++;
        }

    }

    printf("%d\n",ret);
    return 0;
}
