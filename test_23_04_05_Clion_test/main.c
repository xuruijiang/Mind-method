#include <stdio.h>
//测试

int main() {


    int a[]= {0};
    int b = a[0];
    printf("%d\n",b);

    int c[10] = { };
    c[1] = 1;
    printf("%d\n",c[1]);

    int d[10] = {10*1};


    int h = a[0];
    h = 1000;


    for (int i = 0; i < 10; ++i) {
        printf("%d   ",d[i]);
    }
    return 0;
}
