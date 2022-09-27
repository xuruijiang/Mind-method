#include <stdio.h>
#include <stdbool.h>



  struct ListNode {
 	int val;
 	struct ListNode *next;
  };


bool hasCycle(struct ListNode* head ) {
    // write code here
    if(head == NULL){
        return false;
    }

    if(head->next == NULL){
        return false;
    }

    if(head->next == head){
        return true;
    }

    struct ListNode *p1 = head;
    struct ListNode *p2 = head;

    while (p1->next != NULL && p2->next !=NULL && p2->next->next != NULL){



        p1 = p1->next;
        p2 = p2->next->next;
        if(p1 == p2){
            return true;
        }

    }

    return false;

}
int main() {


    struct ListNode listNode[5];


    int a = 0;
    scanf("%d",&a);

    for (int i = 0; i < 5; ++i) {
        scanf("%d",&listNode[i].val);
        if(i == 4 && a != -1){
            listNode[i].next = &listNode[a];
        } else if( i < 4 ){
            listNode[i].next = &listNode[i + 1];
        }

    }

    if(hasCycle(listNode) == false){
        printf("false");
    } else{
        printf("true");
    }
    return 0;
}
