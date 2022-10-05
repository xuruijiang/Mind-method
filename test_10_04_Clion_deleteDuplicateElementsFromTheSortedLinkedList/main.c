//
//  main.c
//  test_10_04_Xcode_deleteDuplicateElementsFromTheSortedLinkedList
//
//  Created by 徐瑞江 on 2022/10/4.
//

#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* deleteDuplicates(struct ListNode* head){

    if(head == NULL){
        return head;
    }
    if(head->next == NULL){

        return head;
    }
    struct ListNode *listNodeOne = head;
    struct ListNode *listNodeTwo = head->next;



    while(listNodeTwo->next != NULL){
        if(listNodeOne->val == listNodeTwo->val){

            listNodeTwo = listNodeTwo->next;
        } else{
            listNodeOne->next = listNodeTwo;
            listNodeOne = listNodeOne->next;
            listNodeTwo = listNodeTwo->next;
        }

    }

    if(listNodeOne->val == listNodeTwo->val){
        ;
    }else {
        listNodeOne->next = listNodeTwo;
        listNodeOne = listNodeTwo;
    }

    listNodeOne->next = NULL;
    return head;

}


int main() {

    struct ListNode listNode[10];

    for (int i = 0; i < 10; ++i) {
        listNode[i].val = i/2;
        if(i < 9){
            listNode[i].next = &listNode[i + 1];
        }
    }
    listNode[9].next = NULL;

    for (int i = 0; i < 10; ++i) {

        printf("%d,",listNode[i].val);
    }

    struct ListNode *list =  deleteDuplicates(listNode);

    printf("\n");
    while (list->next != NULL) {
        printf("%d,",list->val);
        list = list->next;
    }
    printf("%d\n",list->val);
    return 0;
}

