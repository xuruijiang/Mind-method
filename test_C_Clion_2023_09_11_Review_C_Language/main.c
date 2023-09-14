#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    #ifndef __STDC_VERSION__
        puts("这是C90");
        int ver = 90;
    #elif __STDC_VERSION__ == 199901L
        puts("这是C99");
        int ver = 99;
    #elif __STDC_VERSION__ == 201112L
        puts("这是C11");
        int ver = 11;
    #else
        puts("这是什么");
        int ver = 0;
    #endif


    int n = 10;
    int arr[n]; //变长数组不能初始化，变长数组好奇怪
    n = 15;
    for (int i = 0; i < n; ++i) {

        arr[i] = i;
        printf("%d,",arr[i]);
    }

    printf("\n");
    printf("%d\n",(int)sizeof(arr));
    n++;
    printf("%d\n",(int)sizeof(arr));


    n++;
    for (int i = 0; i < n; ++i) {

        printf("%d,",arr[i]);
    }

    printf("\n%d\n",(int)sizeof(arr));

    int c = 0;
    scanf("%d",&c);

    return 0;
}
