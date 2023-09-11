#include <stdio.h>


//#define 定义符号 /宏

#define M 100

#define MAX(x,y) ((x) > (y) ? x:y)
#define ADD(x,y) ((x) + (y))

int main() {
    //printf("%d\n",M);
    int a ,b ,c;
    a = 10;
    b = 20;
    c = MAX(a,b);
    printf("%d\n",c);
    int *p = &a;

    long m = (long)p;
    printf("%d\n",*p);
    printf("%p\n",p);
    printf("%d\n",*((int *)m));

    char ch = 'w';
    char * pc = &ch;

    *pc = 'b';
    printf("%c\n",ch);

    return 0;
}
