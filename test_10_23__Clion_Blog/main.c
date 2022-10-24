#include <stdio.h>

struct stu{

};

int main() {

    struct stu structstu;
    printf("%d\n",sizeof(struct stu) );
    char choose = 0;
    printf("请输入是否认真学习y/n: ");
    scanf("%c",&choose);

    if(choose == 'y')
        printf("走向人生颠覆!!!\n");
    else
        printf("回家放牛!\n");

    return 0;
}
