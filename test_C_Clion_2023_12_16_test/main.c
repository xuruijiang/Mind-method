//#include <stdio.h>
//

//struct stu{
//    int num;
//    char name[20];
//    double score;
//};
//
//
//void input(struct stu* p, int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//
//        scanf("%s%lf",p[i].name, &p[i].score);//变量名.成员名来访问变量中的成员
//        scanf("%s%lf", (p + i)->name, &(p + i)->score);//指针方式访问变量中的成员，这两种方式等价
//
//        scanf("%s",p[i].name);
//    }
//}
//
//int main() {
//    struct stu stu1 = {1,"22",1};
//    struct stu *stu = &stu1;
//    //printf("%d",stu1->name);
//    struct stu tea;
//    scanf("%d%s%lf",(*stu).num,stu->name,&stu->score);
//    return 0;
//}

#include<stdio.h>

struct Student {
    int num;
    char name[10];
    int score;
};

void input(struct Student stu[3], int len)
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%d%s%d", &(stu[i].num), stu[i].name, &(stu[i].score));
    }

}
void sort_by_score(struct Student stu[3], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (stu[j].score > stu[j + 1].score)
            {
                struct Student temp;
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

void print(struct Student* stu, int len)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d %s %d", stu[i].num, stu[i].name, stu[i].score);
        printf("\n");
    }
}
int main()
{
    //结构体数组
    struct Student student[10] = {0};

    input(student, 3);

    sort_by_score(student, 3);

    print(student, 3);

    return 0;
}
