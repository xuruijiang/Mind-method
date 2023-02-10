#include "contact.h"
//1.人的信息：姓名+年龄+性别+地址+电话
//2.通讯中可以存放100个人的信息
//3.功能：
//1》增加联系人
//2》删除指定联系人
//3》查找指定联系人的信息
//4》修改指定联系人的信息
//5》显示所有联系人的信息
//6》排序（名字，年龄）


void menu()
{
    printf("*****************  1.增加联系人 ************************\n");
    printf("*****************  2.删除指定联系人 *********************\n");
    printf("*****************  3.查找指定联系人的信息 ****************\n");
    printf("*****************  4.修改指定联系人的信息 ****************\n");
    printf("*****************  5.显示所有联系人的信息 ****************\n");
    printf("*****************  6.排序（名字，年龄）*******************\n");
    printf("*****************  0.退出*******************************\n");

}

int main() {

    int input = 0;
    //创建通讯录
    Contact contact;
    //初始化通讯录
    InitContact(&contact);


    do {
        menu();
        printf("请选择: ");
        scanf("%d",&input);
        switch (input) {

            case 1:
                add(&contact);
                break;
            case 2:
                break;
            case 3:
                seek(&contact);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                break;
            default:
                printf("输入不合法，请重新输入:\n");
                break;
        }

    } while (input );

    return 0;
}



