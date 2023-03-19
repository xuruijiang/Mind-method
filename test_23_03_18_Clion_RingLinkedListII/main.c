#include <stdio.h>
#include <assert.h>


//--------------------------------------------------------------手动分割--------------------------------------------------------------------//
struct ListNode {
        int val;
        struct ListNode *next;
};
//--------------------------------------------------------------手动分割--------------------------------------------------------------------//
//判断是否有环，且返回入环点。
struct ListNode *detectCycle(struct ListNode *head) {
    assert(head);
    if(head->next == NULL || head->next->next == NULL)
    {
        return NULL;
    }//if

    struct ListNode * slowNode = head;
    struct ListNode * fastNode = head;

    while (fastNode != NULL && fastNode->next != NULL)
    {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;

        if(fastNode == slowNode)
        {
            while (1)
            {
                if(head == slowNode)
                {
                    return head;
                }
                head = head->next;
                slowNode = slowNode->next;
            }//while

        }//if

    }//while

    return NULL;
}//函数结束

//--------------------------------------------------------------手动分割--------------------------------------------------------------------//
int main() {
    printf("Hello, World!\n");
    return 0;
}
