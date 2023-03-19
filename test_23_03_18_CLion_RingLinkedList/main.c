#include <stdio.h>
#include <stdbool.h>

struct ListNode {
        int val;
        struct ListNode *next;
};
//------------------------------------------手动分割------------------------------------------------//
bool hasCycle(struct ListNode *head) {

    if(head->next == NULL || head->next->next == NULL)
    {
        return false;
    }

    struct ListNode *fastNode = head->next;
    struct ListNode *slowNode = head;

    while (fastNode->next != NULL && fastNode->next->next != NULL)
    {
        if(fastNode == slowNode)
        {
            return true;
        }
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }//while

    return false;
}//函数结束
//------------------------------------------手动分割------------------------------------------------//

int main() {
    printf("Hello, World!\n");
    return 0;
}
