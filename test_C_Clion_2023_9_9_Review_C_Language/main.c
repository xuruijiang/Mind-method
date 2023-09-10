#include <stdio.h>

static int g_val = 10;//这个加了static只能在本文件内部使用，把外部链接属性变为内部链接属性，最终使得全局变量，作用域变小。
//修饰函数也一样，函数只能在本文件内使用
int main() {
    printf("Hello, World!\n");
    int a = 10;
    int b = 10;
    printf("%d,%d\n",a,b);
    return 0;
}
