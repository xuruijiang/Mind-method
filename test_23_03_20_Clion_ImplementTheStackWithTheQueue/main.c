#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//--------------------------------------------------------------手动分割---------------------------------------------------------------------//
typedef struct element{
    int val;
    struct element * next;

}Element;

typedef struct quePoint{
    Element * pHead;
    Element * pBack;
    unsigned int size_t ;

}QuePoint ;

typedef struct {
    QuePoint * pOne;
    QuePoint * pTwo;

} MyStack;

//--------------------------------------------------------------手动分割---------------------------------------------------------------------//
//创建包含两个队列指针的结构体
MyStack* myStackCreate()
{
    MyStack * myStack = (MyStack *)malloc(sizeof(MyStack));
    myStack->pOne = NULL;
    myStack->pTwo = NULL;
    myStack->pOne = malloc(sizeof(QuePoint));
    myStack->pTwo = malloc(sizeof(QuePoint));
    myStack->pOne->pHead = NULL;
    myStack->pOne->pBack = NULL;
    myStack->pTwo->pHead = NULL;
    myStack->pTwo->pBack = NULL;
    myStack->pOne->size_t = 0;
    myStack->pTwo->size_t = 0;
    return myStack;

}//函数结束

//--------------------------------------------------------------手动分割---------------------------------------------------------------------//
//插入
void myStackPush(MyStack* obj, int x)
{
    if(obj == NULL || obj->pOne == NULL || obj->pTwo == NULL)
    {
        return;
    }//if

    if(obj->pOne->size_t == 0)
    {
        Element * newNode = (Element*) malloc(sizeof(Element));
        newNode->val = x;
        newNode->next = NULL;
        if(obj->pTwo->size_t == 0)
        {
            obj->pTwo->pHead = newNode;
            obj->pTwo->pBack = newNode;
            obj->pTwo->size_t++;
        }//if
        else
        {
            obj->pTwo->pBack->next = newNode;
            obj->pTwo->pBack = newNode;
            (obj->pTwo->size_t)++;
        }//else



    }//if
    else
    {
        Element * newNode = (Element*) malloc(sizeof(Element));
        newNode->val = x;
        newNode->next = NULL;

        obj->pOne->pBack->next = newNode;
        obj->pOne->pBack = newNode;
        (obj->pOne->size_t)++;
    }//else

}//函数结束

//--------------------------------------------------------------手动分割---------------------------------------------------------------------//
//出栈
int myStackPop(MyStack* obj)
{
    if(obj == NULL || obj->pOne == NULL || obj->pTwo == NULL)
    {
        return true;
    }//if
    if(obj->pOne->size_t == 0 && obj->pTwo->size_t == 0)
    {
        return -1;
    }//if

    if(obj->pOne->size_t == 0)
    {
        Element * newNode = NULL;
        while (obj->pTwo->size_t != 1)
        {
            newNode = obj->pTwo->pHead;
            obj->pTwo->pHead = obj->pTwo->pHead->next;
            (obj->pTwo->size_t)--;

            if(obj->pOne->size_t == 0)
            {
                obj->pOne->pHead = newNode;
                obj->pOne->pBack = newNode;
                obj->pOne->pBack->next = NULL;
                obj->pOne->size_t++;

            }//if
            else
            {
                obj->pOne->pBack->next = newNode;
                newNode->next = NULL;
                obj->pOne->pBack = newNode;
                obj->pOne->size_t++;

            }//else

        }//while

        int num = 0;
        num = obj->pTwo->pHead->val;
        free(obj->pTwo->pHead);
        obj->pTwo->pHead = NULL;
        obj->pTwo->pBack = NULL;
        obj->pTwo->size_t = 0;
        return num;
    }//if
    else
    {
        Element * newNode = NULL;
        while (obj->pOne->size_t != 1)
        {
            newNode = obj->pOne->pHead;
            obj->pOne->pHead = obj->pOne->pHead->next;
            (obj->pOne->size_t)--;

            if(obj->pTwo->size_t == 0)
            {
                obj->pTwo->pHead = newNode;
                obj->pTwo->pBack = newNode;
                obj->pTwo->pBack->next = NULL;
                obj->pTwo->size_t++;

            }//if
            else
            {
                obj->pTwo->pBack->next = newNode;
                newNode->next = NULL;
                obj->pTwo->pBack = newNode;
                obj->pTwo->size_t++;

            }//else

        }//while

        int num = 0;
        num = obj->pOne->pHead->val;
        free(obj->pOne->pHead);
        obj->pOne->pHead = NULL;
        obj->pOne->pBack = NULL;
        obj->pOne->size_t = 0;
        return num;
    }//else

}//函数结束

//--------------------------------------------------------------手动分割---------------------------------------------------------------------//
int myStackTop(MyStack* obj)
{
    if(obj == NULL || obj->pOne == NULL || obj->pTwo == NULL)
    {
        return -1;
    }//if
    if(obj->pOne->size_t == 0 && obj->pTwo->size_t == 0)
    {
        return -1;
    }//if
    else
    {
        if(obj->pOne->size_t > 0)
        {
            return obj->pOne->pBack->val;
        } //if
        else
        {
            return obj->pTwo->pBack->val;
        }//else

    }//else

}//函数结束

bool myStackEmpty(MyStack* obj) {
    if(obj == NULL || obj->pOne == NULL || obj->pTwo == NULL)
    {
        return true;
    }//if
    if(obj->pOne->size_t == 0 && obj->pTwo->size_t == 0)
    {
        return true;
    }//if
    else
    {
        return false;
    }//else

}//函数结束

//--------------------------------------------------------------手动分割---------------------------------------------------------------------//
void myStackFree(MyStack* obj) {

    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/


int main() {
    printf("Hello, World!\n");
    return 0;
}
