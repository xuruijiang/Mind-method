#include <stdio.h>
#include <stdlib.h>

int main() {


    int* p = (int*)malloc(10*sizeof(int) );


    //动态开辟的空间，两种回收方式1主动free2程序结束。
    /*for (int i = 0; i < 10; ++i) {
        p[i] = i;
    }
*/
    for (int i = 0; i < 10; ++i) {
        printf("%d,",p[i]);
    }

    free(p);
    p = NULL;
    return 0;
}
