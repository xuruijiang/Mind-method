#include <stdio.h>

enum Color{
    RED = 5,
    GREEN = 8,
    BLUE
};

union Un{  //公用的空间
    char c[5];
    int i;


};

int main() {


    enum Color c = (enum Color) 9;

    printf("%d\n",c);

    //printf("%d\n",sizeof (c));// 4枚举类型大小都是4，就是一个整型大小


    union Un un;


    //un.i = 1000;
    //un.c = 100;//联合体睡在后面就会覆盖前面的内存。
    printf("%d\n",sizeof (un));//4

    printf("%p\n",&un);
    printf("%p\n",&(un.c));
    printf("%p\n",&(un.i));

    printf("%c,",un.c);
    printf("%d\n",un.i);

    int a = 0x11223344;

    char* p = (char*)&a;

    printf("%d\n",*p);


    return 0;
}
