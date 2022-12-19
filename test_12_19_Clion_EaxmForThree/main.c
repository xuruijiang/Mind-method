
//3。 定义一个结构体类型描述职工的基本信息，一名职工的基本信息包括：
//员工号，姓名，年龄，基本工资。编写程序，实现如下功能：（1）输入10
//位职工的信息，保存在结构体数组中。（2）输入一个字符串x，在数组中查
//找是否有员工的姓名等于字符串 x，如有则输出该员工的员工编号和年龄，
//没有则显示 not found！。
#include <stdio.h>
#include <string.h>
struct Staff {
    char id[20];
    char name[20];
    int age;
    int salary;


};
int main() {

    struct Staff staff[5] = {{"001","张三",18,5500},{"002","李四",19,6600},
            {"003","王二麻子",20,8888},{"004","二狗子",22,12000},{"005","二蛋",31,60000}};

//    struct Staff staff[10];
//    for (int i = 0; i < 10; ++i) {
//        scanf("%s",staff[i].id);
//        scanf("%s",staff[i].name);
//        scanf("%d",&staff[i].age);
//        scanf("%d",&staff[i].salary);
//
//    }


    char x[20] = {0};

    int temp = 0;
    scanf("%s",x);

    for (int i = 0; i < sizeof(staff)/sizeof(staff[0]); ++i) {

        if(strcmp(x,staff[i].name) == 0){
            temp = 1;
            printf("%s\n",staff[i].id);
            printf("%d",staff[i].age);

        }


    }

    if(temp == 0){

        printf("not found!");
    }

    return 0;
}
