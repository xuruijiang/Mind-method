#include <stdio.h>

struct Stu{
    char name[30];
    char sec[5];
    int age;
    int height;

};

//-----------------------------手动分割------------------------------------//
int main() {


    struct Stu stu = {"何清霖","女",20,160};
    //printf("%d\n",(int)sizeof stu);
    printf("%s\n",stu.name);

    //scanf("%d",&stu.age);
    if(stu.age >= 18)
    {
        printf("成年\n");
        printf("可以谈恋爱\n");
    }//if
//    int a = 0;
//    int b = 2;
//    if(a == 1)
//        if(b == 2)
//            printf("hehe\n");
//        else//与最近的if匹配
//            printf("haha\n");

//    int a = 1;
//
//    if(a == 1)
//    {
//        printf("对的");
//    }

    int day = 0;
    scanf("%d",&day);
    switch (day) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            printf("输入错误\n");
            break;
    }
    return 0;
}
