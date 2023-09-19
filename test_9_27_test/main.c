#include<stdio.h>

int main(){

//printf("Hello World!!!");

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
    //int arr[n] = {0};
    scanf("%d",&n);
    return 0;
}