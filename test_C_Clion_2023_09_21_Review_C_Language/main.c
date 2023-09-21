#include <stdio.h>

int test(void)
{
    return printf("aadada\n"); //7

}
//-------------------------------------------//
int main() {
    int ret = test();
    printf("%d\n",ret);
    return 0;
}
//-------------------------------------------//
//(*p)++  要括起来，++优先级高
//函数返回类型不写，默认返回int
