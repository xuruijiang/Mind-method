#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

//通讯录
//通讯录中能存放1000个人的信息
//每个人的信息：
//名字+年龄+性别+电话+地址
//增加个人信息
//删除指定人信息
//修改指定人信息
//查找制定人信息
//排序通讯录的信息

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

enum Choose{
    EXIT = 0,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SORT = 5,
    PRINT
};

void Initialization(int *a){

    for (int i = 0; i < 100; ++i) {
        *(a + i) = 0;
    }
}

/*struct P{
    char name[6];
    int age;
    char happy[6];
};*/
struct PeoInfo{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR]

};
struct PeoInfo peoInfo[100];

void null(){
    for (int i = 0; i < 100; ++i) {
        *(peoInfo[i].name) = NULL;
        *(peoInfo[i].sex) = NULL;
        peoInfo[i].age = 0;
        *(peoInfo[i].tele) = NULL;
        *(peoInfo[i].addr) = NULL;

    }

}

int num[100] = {0};
void menu(){
    printf("***************  1.add      2.del    ****************\n");
    printf("***************  3.search   4.modify ****************\n");
    printf("***************  5.sort     6.print  ****************\n");
    printf("***************  0.exit              ****************\n");

}

int isNull(){

    for (int i = 0; i < 100; ++i) {
        if(strlen(peoInfo[i].name) == 0 &&
           strlen(peoInfo[i].sex ) == 0 &&
           strlen(peoInfo[i].tele) == 0 &&
           strlen(peoInfo[i].addr) == 0 &&
           peoInfo[i].age ==0){

            return i;
        }
    }
    printf("通讯录已满!!!\n");
    return 10000;

}
void add(){

    int number = isNull();

    printf("请输入联系人信息:\n");
    printf("姓      名:");
    scanf("%s",peoInfo[number].name);
    printf("性      别:");
    scanf("%s",peoInfo[number].sex);
    printf("年      龄:");
    scanf("%d",&peoInfo[number].age);
    printf("电 话 号 码:");
    scanf("%s",peoInfo[number].tele);
    printf("地      址:");
    scanf("%s",peoInfo[number].addr);

    printf("添加联系人成功!!!\n");

}

void print_all(){

    int count = 0;
    for (int i = 0; i < 100; ++i) {
        if(strlen(peoInfo[i].name) != 0 ||
           strlen(peoInfo[i].sex ) != 0 ||
           strlen(peoInfo[i].tele) != 0 ||
           strlen(peoInfo[i].addr) != 0 ||
           peoInfo[i].age !=0){


            count++;
            printf("姓      名:");
            printf("%s\n",peoInfo[i].name);
            printf("性      别:");
            printf("%s\n",peoInfo[i].sex);
            printf("年      龄:");
            printf("%d\n",peoInfo[i].age);
            printf("电 话 号 码:");
            printf("%s\n",peoInfo[i].tele);
            printf("地      址:");
            printf("%s\n",peoInfo[i].addr);
            printf("\n");

        }
    }

    if(count == 0){
        printf("通讯录空空如也！！！！！\n");

    }


}

//目前只用姓名搜索联系人
int*  search(int *a){

    printf("请输入姓名:");
    char name[20];
    scanf("%s",name);

    int count = 0;

    for (int i = 0; i < 100; ++i) {
        if(strcmp(peoInfo[i].name,name) == 0){

            *(a + count) = i;
            count++;

        }
    }

    if(count == 0){
        return NULL;
    }
    return a;
}

void print_search(int a[100]){


    int i = -1;

    do {
        i++;
        printf("姓      名:");
        printf("%s\n",peoInfo[a[i]].name);
        printf("性      别:");
        printf("%s\n",peoInfo[a[i]].sex);
        printf("年      龄:");
        printf("%d\n",peoInfo[a[i]].age);
        printf("电 话 号 码:");
        printf("%s\n",peoInfo[a[i]].tele);
        printf("地      址:");
        printf("%s\n",peoInfo[a[i]].addr);
        printf("\n");

    } while (a[i] < a [i + 1]);
}

//删除也是用姓名查找，删除所有该姓名的通讯录信息
void del(){
    if(search(num) == NULL){
        printf("查无此人!!!\n");
        return;
    } else{
        print_search(num);//这个有问题，两个指针指向同一块内存，之后又对其中的指针进行滞空？
        printf("是否选择删除Y/N:");
        char chooseOne;
        scanf("%c",&chooseOne);
        while (1){
            scanf("%c",&chooseOne);

            if(chooseOne == 'Y' || chooseOne == 'y'){
                int  i = 0;
                do {
                    *(peoInfo[num[i]].name) = NULL;
                    *(peoInfo[num[i]].sex) = NULL;
                    peoInfo[num[i]].age = 0;
                    *(peoInfo[num[i]].tele) = NULL;
                    *(peoInfo[num[i]].addr) = NULL;
                    i++;
                } while (num[i] > 0);


                printf("全部删除成功!!!\n");
                Initialization(num);
                return;
            } else if(chooseOne == 'N' || chooseOne == 'n'){

                printf("退出成功!!!");
                return;
            } else{

                printf("输入不合法，请重新输入！！！");
                continue;
            }
        }
    }

    //结构体直接滞空，不知道有没有方法，先不写。

}

void modify( int a){

    printf("名字: %s -> ",peoInfo[a].name);
    scanf("%s",peoInfo[a].name);
    printf("性别: %s -> ",peoInfo[a].sex);
    scanf("%s",peoInfo[a].sex);
    printf("年龄: %d -> ",peoInfo[a].age);
    scanf("%d",&peoInfo[a].age);
    printf("电话: %s -> ",peoInfo[a].tele);
    scanf("%s",peoInfo[a].tele);
    printf("地址: %s -> ",peoInfo[a].addr);
    scanf("%s",peoInfo[a].addr);


    printf("修改成功\n");
}

void sort(){

    int  choose = 0;
    while (1){
        printf("请输入排序方式:1.按姓名排序 2.按年龄从小到大排");
        scanf("%d", &choose);
        if(choose == 1 || choose == 2){
            break;
        } else{
            printf("输入不合法，请重新输入！！！\n");
        }
    }

    struct PeoInfo structPeoInfo;

    if(choose){
        for (int i = 99; i >0; ++i) { //错了，这里要双层循环，搞忘记了尴尬。。。

            if(*(peoInfo[i].name) == NULL && *(peoInfo[i - 1].name) == NULL ){
                continue;
            }if(*(peoInfo[i].name) == NULL){
                continue;
            }if(*(peoInfo[i].name) != NULL && *(peoInfo[i - 1].name) == NULL ){
                structPeoInfo = peoInfo[i];
                peoInfo[i] = peoInfo[i -1];
                peoInfo[i - 1] = structPeoInfo;
            } if(strcmp(peoInfo[i].name,peoInfo[i - 1].name) >= 0){
                continue;
            } else{
                structPeoInfo = peoInfo[i];
                peoInfo[i] = peoInfo[i -1];
                peoInfo[i - 1] = structPeoInfo;
            }


        }

    }





}

int main() {
    /*const int M = 10;
    int a[M] = {0};
    for (int i =0; i < M; i++) {
        printf("%d,",a[i]);
    }*/ //严格意义是不行的。
    /*struct P * p = NULL;

    p =(struct P *) malloc(sizeof(struct P));

    scanf("%s",p->name);

    printf("%p\n",p->name);
    printf("%c\n",*((char *)p + 6));
    printf("%p\n",&(p->age));
    printf("%p\n",p->happy);*/

    null();

    fopen("/Users/xuruijiang/Pictures/图标/购物2.txt ","w");

    /*char name[] = "sasas";
    printf("%s",name);*/
    int number[100] = {0};
    int choose;

    do {

        menu();
        printf("请输入对应的操作数: ");
        scanf("%d",&choose);

        switch (choose) {

            case ADD:
                add();
                break;
            case DEL:
                del();
                break;
            case SEARCH:


                if(search(number) == NULL){
                    printf("查无此人!!!\n");
                } else{
                    print_search(number);
                }

                Initialization(number);

                break;
            case MODIFY:
                if(search(number) == NULL){
                    printf("查无此人!!!\n");
                    break;
                } else{
                    print_search(number);
                }

                if(number[1] != 0){
                    printf("请输入要修改的哪位信息1/2/3...\n");
                    int a = 0 ;
                    scanf("%d",&a);
                    modify(a -1 );
                } else{

                    printf("是否选择更改Y/N:");
                    char chooseOne;
                    scanf("%c",&chooseOne);

                    while (1) {
                        scanf("%c",&chooseOne);
                        if (chooseOne == 'Y' || chooseOne == 'y') {
                            modify(number[0]);
                        } else if (chooseOne == 'N' || chooseOne == 'n') {

                        } else{

                            printf("输入不合法，请重新输入！！！");
                            continue;
                        }

                        break;
                    }
                }

                Initialization(number);

                break;

            case SORT:
                sort();
                break;
            case PRINT:
                print_all();
                break;
            case EXIT:
                choose = 0;
                break;
            default:
                printf("输入不合法，请重新输入");
        }
    } while (choose);



    return 0;
}
