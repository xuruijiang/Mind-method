#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------手动分割---------------------------------------------------------------------//
struct Node {
         int val;
         struct Node *next;
         struct Node *random;
};

//-----------------------------------------------------------------------------手动分割---------------------------------------------------------------------//
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
    {
        return NULL;
    }//if
    else if(head->next == NULL)
    {
        struct Node * newNode = malloc(sizeof(struct Node));
        newNode->val = head->val;
        newNode->next = NULL;

        if(head->random == NULL)
        {
            newNode->random = NULL;
        }//if
        else
        {
            newNode->random = newNode;
        }//else

        return newNode;
    }//else if


    struct Node * newNode = NULL;
    //struct Node * preNode = head->next;
    struct Node * curNode = head;

    while(curNode)
    {
        newNode = malloc(sizeof(struct Node));
        newNode->val = curNode->val;
        newNode->next = curNode->next;
        curNode->next = newNode;


        curNode = newNode->next;
        if (curNode == NULL)
        {
            break;
        }
    }//while

    curNode = head;
    newNode = head->next;
    while (curNode)
    {
        if(curNode->random == NULL)
        {
            newNode->random = NULL;
        }//if
        else
        {
            newNode->random = curNode->random->next;
        }

        if(newNode->next == NULL)
        {
            break;
        }//if

        curNode = curNode->next->next;
        newNode = newNode->next->next;

    }//while

    curNode = head->next;
    newNode = curNode;

    while (newNode->next != NULL)
    {
        newNode->next = newNode->next->next;
        newNode = newNode->next;
    }//while

    return curNode;

}//函数结束

//-----------------------------------------------------------------------------手动分割---------------------------------------------------------------------//

int main() {
    printf("Hello, World!\n");
    return 0;
}
