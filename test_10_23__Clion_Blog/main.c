#include <stdio.h>

int main() {

    char choose = 0;
    printf("请输入是否认真学习y/n: ");
    scanf("%c",&choose);

    if(choose == 'y')
        printf("走向人生颠覆!!!\n");
    else
        printf("回家放牛!\n");

    return 0;
}
