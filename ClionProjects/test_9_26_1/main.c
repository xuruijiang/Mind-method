/*
#include <stdio.h>


*/
/**
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 * };
 *//*




struct ListNode{
    int val;
    struct ListNode *next;

};
void reorderList(struct ListNode* head ) {
    // write code here

    int i = 0;
    int count1 = 0;
    int count2 = 0;
    int a = 1;
    int b = 0;


    while (1){

        if(head[i].next != NULL){
            count2++;
        } else{
            count2++;
            break;
        }

    }

    for (int j = 0; j <count2; ++j) {


        if(a){
            head[count1 + j].next = &head[count2 - 1 - j];
        } else if(b){
            head[count2 - j].next = &head[count1 + j];
        }

        a = a^b;
        b = a^b;
        a = a^b;

    }




}
int main() {


//    int a;
//    scanf("%d",&a);
//    printf("%d\n",a);
    struct ListNode listNode[10];
   */
/* printf("%d\n",sizeof(listNode[1]) );
    struct ListNode *p = &listNode[9];
    printf("%d\n",sizeof(p));
    printf("%d\n",sizeof((p + 1111)));*//*

    listNode[9].next = NULL;

    for (int i = 0; i < 10; ++i) {
        scanf("%d",&(listNode[i].val));

        if(i != 9 ){
            listNode[i].next = &listNode[i + 1];
        }

    }


    reorderList(listNode);

//    for (int i = 0; i < 10; ++i) {
//        printf("%d",listNode[i].val);
//    }


    return 0;
}

*/


#include <stdio.h>

    struct ListNode {
        int val;
        struct ListNode *next;
    };

void reorderList(struct ListNode* head ) {
    // write code here


}

int main(){


    struct ListNode listNode[10];

    printf("%p",listNode[1].next);
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&(listNode[i].val));


#if i - 9
        listNode[i].next = &(listNode[i + 1]);
#endif
    }



    return 0;
}