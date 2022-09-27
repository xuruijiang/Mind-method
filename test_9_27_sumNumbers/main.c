#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//先放着

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){


    if(l1->val == 0){
        return l2;
    } else if(l2->val == 0){
        return l1;
    }

    struct ListNode * listNode1 = NULL;
    struct ListNode * listNode2 = NULL;





    int lenthOne = 0;
    int lenthTwo = 0;
    int count = 0;
    int longth = 0;
    int shorty = 0;
    char str[101];
    int sum = 0;
    listNode1 = l1;
    int s1 = 0,s2 = 0;
    while(NULL != listNode1->next){
        s1++;
        listNode1 = listNode1->next;
    }
    listNode1 = l1;

    listNode2 = l2;
    while(NULL != listNode2->next){
        s2++;
        listNode2 = listNode2->next;
    }
    listNode2 = l2;
    while ( count < s1 ){
        count++;

        if(listNode1->val != 0){
            lenthOne = count;
        }
        listNode1 = listNode1->next;
    }

    count = 0;

    listNode2 = l2;
    while (count < s2  ){
        count++;
        if(listNode2->val != 0){
            lenthTwo = count;
        }
        listNode2 = listNode2->next;
    }
    count = 0;


    longth = (lenthOne > lenthTwo)? lenthOne:lenthTwo;
    shorty = (lenthOne < lenthTwo)? lenthOne:lenthTwo;

    listNode1 = l1;
    listNode2 = l2;
    for (int i = 0; i < longth; ++i) {

        if(i < shorty){
            if((sum = listNode1->val + listNode2->val + count) >= 10 ){
                str[i] = (char)((sum%10) + 48);
                count = 1;
                listNode1 = listNode1->next;
                listNode2 = listNode2->next;
            } else{
                str[i] = (char)(sum + 48);
                count =0;
                listNode1 = listNode1->next;
                listNode2 = listNode2->next;
            }

        } else if(lenthOne < lenthTwo){

            if( (sum = listNode2->val + count) >= 10){
                str[i] = (char)((sum%10) + 48);
                count = 1;
                listNode2 = listNode2->next;
            } else{
                str[i] = (char)(sum + 48);
                count =0;
                listNode2 = listNode2->next;
            }

        } else if(lenthOne > lenthTwo){

            if( (sum = listNode1->val + count) >= 10){
                str[i] = (char)((sum%10) + 48);
                count = 1;
                listNode1 = listNode1->next;
            } else{
                str[i] = (char)(sum + 48);
                count =0;
                listNode1 = listNode1->next;
            }

        }


    }

    if(count == 1){
        str[longth] =(char)(1 + 48);
    }

    //listNode1 = l1;

    struct ListNode *p = (struct ListNode*)malloc(strlen(str) * sizeof(struct ListNode));

    listNode1 = p;
    for(int i = 0;i < strlen(str) - 1 ;++i){
        listNode1->val =(int)(str[i] - 48);
        listNode1 = listNode1->next;
    }


    return p;

}


int main() {

//    char sss[] = "123456";
//    printf("%c",sss[4]);

    struct ListNode listNode1[100];
    struct ListNode listNode2[100];


    for (int i = 0; i < 99; ++i) {
        listNode1[i].val = 0;
        listNode2[i].val = 0;
        listNode1[i].next = &listNode1[i + 1];
        listNode2[i].next = &listNode2[i + 1];
    }


    char str1[100];
    char str2[100];
    scanf("%s %s",str1,str2);

    int sum1 = (int)strlen(str1);
    int sum2 = (int)strlen(str2);


    for (int i = 0; i < sum1; ++i) {
        listNode1[i].val = (int)(str1[sum1 - i -1] - 48);

    }

    for (int i = 0; i < sum2; ++i) {
        listNode2[i].val = (int)(str2[sum2 -i -1] - 48);

    }



    addTwoNumbers(listNode1,listNode2 );

    printf("%d%d%d\n",listNode1->val,(listNode1->next)->val,((listNode1->next)->next)->val);

    return 0;
}


