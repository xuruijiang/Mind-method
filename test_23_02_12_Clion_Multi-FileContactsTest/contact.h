//
// Created by 徐瑞江 on 2023/2/12.
//

#ifndef TEST_23_02_12_CLION_MULTI_FILECONTACTSTEST_CONTACT_H
#define TEST_23_02_12_CLION_MULTI_FILECONTACTSTEST_CONTACT_H

#endif //TEST_23_02_12_CLION_MULTI_FILECONTACTSTEST_CONTACT_H
#include <stdio.h>
#include <string.h>

#define N 100
typedef struct PeoInfo {

    char name[20];
    int age;
    char sex[5];
    char address[30];
    char phone[12];

}PeoInfo;

typedef struct Contact{

    PeoInfo data[N];
    int sz;

}Contact;

void menu();
void add(Contact * pc);
void del(Contact *pc);
void seek(Contact *pc);
void modify(Contact * pc);
void show(Contact * pc);
void sort(Contact *pc);
void InitContact(Contact * pc);