#include "contact.h"
//
// Created by 徐瑞江 on 2023/2/9.
//


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

/*void del(Contact *pc){



}*/

//查找方式

void seekName(Contact *pc,int * tmp,int * tepDate){

    char name[20];
    printf("请输入姓名:");
    scanf("%s",name);

    for (int i = 0; i < pc->sz; ++i) {
        if(strcmp(pc->data->name,name) == 0 ){
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
        printf("%d",i + 1);
        printf("    姓名：%s\n",pc->data[tepDate[i]].name);
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