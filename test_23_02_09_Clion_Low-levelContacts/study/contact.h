
//
// Created by 徐瑞江 on 2023/2/9.
//

#ifndef TEST_23_02_09_CLION_LOW_LEVELCONTACTS_CONTACT_H
#define TEST_23_02_09_CLION_LOW_LEVELCONTACTS_CONTACT_H
#endif //TEST_23_02_09_CLION_LOW_LEVELCONTACTS_CONTACT_H


#include <stdio.h>
#include <string.h>

//人的信息

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

void InitContact(Contact *pc);
void menu_t();
void add(Contact *pc);
void seek(Contact *pc);
void seekName(Contact *pc,int * tmp,int * tepDate);
void seekAge(Contact *pc,int * tmp,int * tepDate);
void seekSex(Contact *pc,int * tmp,int * tepDate);
void seekAddress(Contact *pc,int * tmp,int * tepDate);
void seekPhone(Contact *pc,int * tmp,int * tepDate);
void print(Contact *pc,int tmp,int * tepDate);
void initTepDate(int * tmp,int * tepDate);
