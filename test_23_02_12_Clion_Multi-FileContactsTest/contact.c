//
// Created by 徐瑞江 on 2023/2/12.
//
#include "contact.h"

void menu_t()
{
    printf("*****************  1.姓名 ***********************\n");
    printf("*****************  2.年龄 ***********************\n");
    printf("*****************  3.性别 ***********************\n");
    printf("*****************  4.地址 ***********************\n");
    printf("*****************  5.电话 ***********************\n");
    printf("*****************  0.退出************************\n");

}

void InitContact(Contact * pc){

    pc->sz = 0;
    memset(pc->data,0,sizeof(pc->data) );

}

void add(Contact * pc){

    if(pc->sz == N ){
        printf("通讯录已满，无法添加!\n");
        return;
    }
    printf("请输入姓名:");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入年龄:");
    scanf("%d", &pc->data[pc->sz].age);
    printf("请输入性别:");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入地址:");
    scanf("%s", pc->data[pc->sz].address);
    printf("请输入电话号码:");
    scanf("%s", pc->data[pc->sz].phone);

    (pc->sz)++;
}



//查找方式

void seekName(Contact *pc,int * tmp,int * tepDate){

    char name[20];
    printf("请输入姓名:");
    scanf("%s",name);

    for (int i = 0; i < pc->sz; ++i) {
        if(strcmp(pc->data[i].name,name) == 0 ){
            tepDate[*tmp] = i;
            (*tmp)++;

        }

    }

}

void seekAge(Contact *pc,int * tmp,int * tepDate){

    int age;
    printf("请输入年龄:");
    scanf("%d",&age);

    for (int i = 0; i < pc->sz; ++i) {
        if(pc->data->age == age ){
            tepDate[*tmp] = i;
            (*tmp)++;

        }

    }

}

void seekSex(Contact *pc,int * tmp,int * tepDate){

    char sex[5];
    printf("请输入性别:");
    scanf("%s",sex);

    for (int i = 0; i < pc->sz; ++i) {
        if(strcmp(pc->data->sex,sex) == 0 ){
            tepDate[*tmp] = i;
            (*tmp)++;

        }

    }

}

void seekAddress(Contact *pc,int * tmp,int * tepDate){

    char address[30];
    printf("请输入地址:");
    scanf("%s",address);

    for (int i = 0; i < pc->sz; ++i) {
        if(strcmp(pc->data->address,address) == 0 ){
            tepDate[*tmp] = i;
            (*tmp)++;

        }

    }

}

void seekPhone(Contact *pc,int * tmp,int * tepDate){

    char phone[12];
    printf("请输入电话:");
    scanf("%s",phone);

    for (int i = 0; i < pc->sz; ++i) {
        if(strcmp(pc->data->phone,phone) == 0 ){
            tepDate[*tmp] = i;
            (*tmp)++;

        }

    }

}

void print(Contact *pc,int tmp,int * tepDate){
    for (int i = 0; i < tmp; ++i) {
        printf("%d.",i + 1);
        printf("  姓名：%s\n",pc->data[tepDate[i]].name);
        printf("    年龄：%d\n",pc->data[tepDate[i]].age);
        printf("    性别：%s\n",pc->data[tepDate[i]].sex);
        printf("    地址：%s\n",pc->data[tepDate[i]].address);
        printf("    电话：%s\n",pc->data[tepDate[i]].phone);

    }

}
void initTepDate(int * tmp,int * tepDate){

    for (int i = 0; i < *tmp; ++i) {
        tepDate[i] = 0;
    }

    *tmp = 0;

}

void del_one(Contact * pc,int x){

    for (int i = x; i < pc->sz; ++i) {
        pc->data[i] = pc->data[ i + 1 ];

    }

    (pc->sz)--;

}

void del(Contact *pc){
    int tepDate[N] = {0};
    int tmp = 0;
    int input;
    int choose = 0;
    do {
        menu_t();
        printf("请选择查找方式: ");
        scanf("%d",&input);
        switch (input) {

            case 1:
                seekName(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择删除对象：");
                scanf("%d",&choose);
                del_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 2:
                seekAge(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择删除对象：");
                scanf("%d",&choose);
                del_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 3:
                seekSex(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择删除对象：");
                scanf("%d",&choose);
                del_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 4:
                seekAddress(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择删除对象：");
                scanf("%d",&choose);
                del_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 5:
                seekPhone(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择删除对象：");
                scanf("%d",&choose);
                del_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 0:
                break;
            default:
                printf("输入不合法，请重新输入:\n");
                break;
        }

    } while (input );



}

void seek(Contact *pc){
    int tepDate[N] = {0};
    int tmp = 0;
    int input;

    do {
        menu_t();
        printf("请选择查找方式: ");
        scanf("%d",&input);
        switch (input) {

            case 1:
                seekName(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                initTepDate(&tmp,tepDate);
                break;
            case 2:
                seekAge(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                initTepDate(&tmp,tepDate);
                break;
            case 3:
                seekSex(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                initTepDate(&tmp,tepDate);
                break;
            case 4:
                seekAddress(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                initTepDate(&tmp,tepDate);
                break;
            case 5:
                seekPhone(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                initTepDate(&tmp,tepDate);
                break;
            case 0:
                break;
            default:
                printf("输入不合法，请重新输入:\n");
                break;
        }

    } while (input );


}

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

void show(Contact * pc){
    for (int i = 0; i < pc->sz; ++i) {
        printf("%d.",i + 1);
        printf("  姓名：%s\n",pc->data[i].name);
        printf("    年龄：%d\n",pc->data[i].age);
        printf("    性别：%s\n",pc->data[i].sex);
        printf("    地址：%s\n",pc->data[i].address);
        printf("    电话：%s\n",pc->data[i].phone);

    }


}

//修改

void modify_one(Contact *pc,int x){


    int input = 0;
    do {
        menu_t();
        printf("请选择修改信息：");
        scanf("%d",&input);

        switch (input) {
            case 1:
                printf("请输入姓名:");
                scanf("%s",pc->data[x].name);
                printf("修改成功\n");
                break;
            case 2:
                printf("请输入年龄:");
                scanf("%d",&(pc->data[x].age));
                printf("修改成功\n");
                break;
            case 3:
                printf("请输入性别:");
                scanf("%s",pc->data[x].sex);
                printf("修改成功\n");
                break;
            case 4:
                printf("请输入地址:");
                scanf("%s",pc->data[x].address);
                printf("修改成功\n");
                break;
            case 5:
                printf("请输入电话:");
                scanf("%s",pc->data[x].phone);
                printf("修改成功\n");
                break;
            case 0:
                break;
        }

    } while (input );





}
void modify(Contact * pc){
    int tepDate[N] = {0};
    int tmp = 0;
    int input;
    int choose = 0;
    do {
        menu_t();
        printf("请选择查找方式: ");
        scanf("%d",&input);
        switch (input) {

            case 1:
                seekName(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择修改对象：");
                scanf("%d",&choose);
                modify_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 2:
                seekAge(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择修改对象：");
                scanf("%d",&choose);
                modify_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 3:
                seekSex(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择修改对象：");
                scanf("%d",&choose);
                modify_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 4:
                seekAddress(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择修改对象：");
                scanf("%d",&choose);
                modify_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 5:
                seekPhone(pc,&tmp,tepDate);
                print(pc,tmp,tepDate);
                printf("请选择修改对象：");
                scanf("%d",&choose);
                modify_one(pc,tepDate[choose - 1]);
                initTepDate(&tmp,tepDate);
                break;
            case 0:
                break;
            default:
                printf("输入不合法，请重新输入:\n");
                break;
        }

    } while (input );

}

//排序

void sort(Contact *pc){


}