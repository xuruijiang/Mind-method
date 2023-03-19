#include <stdio.h>


//------------------------------------------------手动分割-----------------------------------------------------//
struct ListNode {
  int val;
  struct ListNode *next;
};
//------------------------------------------------手动分割-----------------------------------------------------//

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{

    struct ListNode *newNodeA = headA;
    struct ListNode *newNodeB = headB;
    int numA = 0;
    int numB = 0;
    while(newNodeA != NULL || newNodeB != NULL)
    {
        if(newNodeA != NULL && newNodeB != NULL)
        {
            newNodeA = newNodeA->next;
            newNodeB = newNodeB->next;

            numA++;
            numB++;
        }//if
        else if(newNodeA != NULL)
        {
            newNodeA = newNodeA->next;
            numA++;
        }//else if
        else
        {
            newNodeB = newNodeB->next;
            numB++;
        }//else
    }//while

    if(newNodeA != newNodeB)
    {
        return NULL;
    }

    if(numA > numB)
    {
        for(int i = 0;i < numA - numB ;i++)
        {
            headA = headA->next;
        }//for
    }//if
    else if(numA < numB)
    {
        for(int i = 0;i < numB - numA ;i++)
        {
            headB = headB->next;
        }//for
    }//else if
    else
    {
        ;
    }

    while(headA != NULL)
    {
        if(headA == headB)
        {
            return headA;
        }//if

        headA = headA->next;
        headB = headB->next;
    }//while
}
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//    struct ListNode * newListA = headA;
//    struct ListNode * newListB = headB;
//    int differA = 0;
//    int differB = 0;
//
//    while (newListA->next != NULL || newListB->next != NULL)
//    {
//        if(newListA->next != NULL && newListB->next == NULL)
//        {
//            differA++;
//            newListA = newListA->next;
//        }//if
//        else if(newListA->next == NULL && newListB->next != NULL)
//        {
//            differB++;
//            newListB = newListA->next;
//        }//else if
//    }//while
//
//    if(differA > 0)
//    {
//        while(differA--)
//        {
//            headA = headA->next;
//        }//while
//
//        while (headA->next != NULL){
//            if(headA == headB)
//            {
//                return headA;
//            }//if
//
//            headA = headA->next;
//            headB = headB->next;
//        }//while
//
//        if(headA == headB)
//        {
//            return headA;
//        }//if
//
//        return NULL;
//    }
//    else if(differB > 0)
//    {
//
//        while(differB--)
//        {
//            headB = headB->next;
//        }//while
//
//        while (headB->next != NULL){
//            if(headA == headB)
//            {
//                return headA;
//            }//if
//
//            headA = headA->next;
//            headB = headB->next;
//        }//while
//
//        if(headA == headB)
//        {
//            return headA;
//        }//if
//
//        return NULL;
//
//    }//else if
//    else
//    {
//        while (headA != NULL)
//        {
//            if(headA == headB)
//            {
//                return headA;
//            }//if
//            headA = headA->next;
//            headB = headB->next;
//        }
//
//        return NULL;
//    }
//}//函数结束
//------------------------------------------------手动分割-----------------------------------------------------//
int main()
{
    printf("Hello, World!\n");
    return 0;
}//main
