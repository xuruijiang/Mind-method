#include <stdio.h>
#include <stdbool.h>

//-----------------------------------手动分割线---------------------------------------//
//结构体
struct ListNode{
    int val;
    struct ListNode * next;

}; //结构体结束

//-----------------------------------手动分割线---------------------------------------//

void InverseOrder(struct ListNode * head)
{

    if(head->next->next == NULL)
    {
        struct ListNode *preList = head->next;
        head->next = NULL;
        preList->next = head;
        return;
    }//if
    struct ListNode * midList = head->next;
    struct ListNode * preList = head->next->next;
    head->next = NULL;

    while (preList->next != NULL)
    {
        midList->next = head;
        head = midList;
        midList = preList;
        preList = preList->next;

    }//while结束

    midList->next = head;
    preList->next = midList;


}//函数结束

//-----------------------------------手动分割线---------------------------------------//
//判断是否为回文结构
bool IsPalindrome(struct ListNode* head)
{

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    if(head->next == NULL)
    {
        return true;
    }//if
    if(head->next->next == NULL)
    {
        if(head->val == head->next->val)
        {
            return true;
        }//if
        else
        {
            return false;
        }//else
    }//if结束
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }//while结束

    if(fast->next == NULL)
    {
        InverseOrder(slow);
        while (head != slow)
        {
            if (head->val != fast->val)
            {
                return false;
            }//if结束

            head = head->next;
            fast = fast->next;

        }//while结束

        return true;

    }//if结束
    else
    {
        fast = fast->next;
        InverseOrder(slow->next);

        while (fast != slow->next)
        {
            if (head->val != fast->val)
            {
                return false;
            }//if结束

            head = head->next;
            fast = fast->next;

        }//while结束

        if(head->val != fast->val)
        {
            return false;
        }//if结束

        return true;
    }//else结束

}//函数结束
//-----------------------------------手动分割线---------------------------------------//

int main()
{

    struct ListNode listNode1 = {1};
    struct ListNode listNode2 = {2};
    struct ListNode listNode3 = {3};
    struct ListNode listNode4 = {2};
    struct ListNode listNode5 = {2};

    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;
    listNode4.next = &listNode5;
    listNode5.next =NULL;
    printf("%d", IsPalindrome(&listNode1));

    return 0;
}//主函数结束
//-----------------------------------手动分割线---------------------------------------//