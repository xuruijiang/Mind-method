#include <stdio.h>
#include <string.h>
//3. 定义一个结构体类型描述职工的基本信息，一名职工的
//基本信息包括：员工号，姓名，年龄，基本工资。编写
//程序，实现如下功能：（1）输入10位职工的信息，保存在
//结构体数组中。（2）输入一个字符串 x，在数组中查找
//是否有员工的姓名等于字符串x，如有则输出该员工的员
//工编号和年龄，没有则显示 not found！。


struct Staff{
    char Id[20];
    char Name[20];
    int Age;
    int Wage;
};
int main() {
   struct Staff staff[10];

    for (int i = 0; i < 10; ++i) {
        scanf("%s",staff[i].Id);
        scanf("%s",staff[i].Name);
        scanf("%d",&staff[i].Age);
        scanf("%d",&staff[i].Wage);
    }
    char s[20];
    scanf("%s",s);
    int choose = 0;
    for (int i = 0; i < 10; ++i) {
        if(0==strcmp(s,staff[i].Name))
        {
            choose = 1;
            printf("Id = %s, Age = %d",staff[i].Id,staff[i].Age);
            break;
        }
    }

    if(choose==0)
    {
        printf("not found!");
    }

    return 0;
}
