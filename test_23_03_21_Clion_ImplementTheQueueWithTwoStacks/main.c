#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//


typedef struct stack{
    int * arr;
    int *pTop;
    unsigned Capacity;
    unsigned int size_t;

}Stack;

typedef struct {
    Stack * stackOne;
    Stack * stackTwo;
} MyQueue;

//给栈扩容
void dilatation(Stack * stack){

    stack->arr = (int *) realloc(stack->arr,(stack->Capacity + 1)*2 * sizeof(int));
    stack->pTop = stack->arr + stack->size_t;
    stack->Capacity = (stack->Capacity + 1) * 2;


}


//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//
//创建双队列
MyQueue* myQueueCreate() {

    MyQueue * myQueue = (MyQueue*)malloc(sizeof(MyQueue));
    myQueue->stackOne = (Stack*) malloc(sizeof (Stack));
    myQueue->stackOne = (Stack*) malloc(sizeof (Stack));
    myQueue->stackOne->arr = NULL;
    myQueue->stackOne->pTop = NULL;
    myQueue->stackOne->Capacity = 0;
    myQueue->stackOne->size_t = 0;

    myQueue->stackTwo->arr = NULL;
    myQueue->stackTwo->pTop = NULL;
    myQueue->stackTwo->Capacity = 0;
    myQueue->stackTwo->size_t = 0;

    return myQueue;


}//函数结束

//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//
//入数据
void myQueuePush(MyQueue* obj, int x) {
    if(obj == NULL || obj->stackOne == NULL || obj->stackTwo == NULL)
    {
        return;
    }//if
    else
    {
        if (obj->stackOne->size_t == obj->stackOne->Capacity )
        {
            dilatation(obj->stackOne);

        }//if
        else
        {
            ;
        }//else

        *(obj->stackOne->pTop) = x;
        obj->stackOne->pTop++;
        obj->stackOne->size_t++;



    }//else

}//函数结束

//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//

void stackPush(Stack * stack, int x)
{
    if(stack->size_t == stack->Capacity)
    {
        dilatation(stack);
    }//if
    else
    {
        ;
    }//else

    *(stack->pTop) = x;
    stack->pTop++;
    stack->size_t++;

}//函数结束

//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//
//出数据
int myQueuePop(MyQueue* obj) {

    int num = 0;
    if(obj == NULL || obj->stackOne == NULL || obj->stackTwo == NULL || obj->stackOne->size_t == 0)
    {
        return -1;
    }//if
    else
    {
        while (obj->stackOne->pTop != obj->stackOne->arr + 1)
        {
            obj->stackOne->pTop--;
            obj->stackOne->size_t--;
            stackPush(obj->stackTwo,*(obj->stackOne->pTop));



        }//while

        obj->stackOne->pTop--;
        obj->stackOne->size_t--;
        num = *obj->stackOne->pTop;


        while (obj->stackTwo->pTop != obj->stackTwo->arr)
        {
            obj->stackTwo->pTop--;
            obj->stackTwo->size_t--;
            stackPush(obj->stackOne,*obj->stackTwo->pTop);
        }//while
    }//else
    return num;
}//函数结束

//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//
//查看队列头
int myQueuePeek(MyQueue* obj) {
    if(obj == NULL || obj->stackOne == NULL || obj->stackTwo == NULL || obj->stackOne->size_t == 0)
    {
        return -1;
    }//if
    else
    {
        return *(obj->stackOne->pTop - obj->stackOne->size_t);

    }//else
}//函数结束

//---------------------------------------------------------------------手动分割--------------------------------------------------------------------------//
//判断队列是否为空
bool myQueueEmpty(MyQueue* obj) {
    if(obj == NULL || obj->stackOne == NULL || obj->stackTwo == NULL || obj->stackOne->size_t == 0)
    {
        return true;
    }//if
    else
    {
        return false;

    }//else

}//函数结束

//释放
void myQueueFree(MyQueue* obj) {
    if(obj == NULL || obj->stackOne == NULL || obj->stackTwo == NULL )
    {
        return ;
    }//if
    else
    {
        if(obj->stackOne->arr != NULL)
        {
            if(obj->stackTwo->arr != NULL)
            {
                free(obj->stackTwo->arr);
                obj->stackTwo->arr = NULL;
                obj->stackTwo->pTop = NULL;

            }//if
            else
            {
                ;
            }//else

            free(obj->stackOne->arr);
            obj->stackOne->arr = NULL;
            obj->stackOne->pTop = NULL;

            free(obj->stackOne);
            free(obj->stackTwo);
            obj->stackOne = NULL;
            obj->stackTwo = NULL;
            free(obj);
            obj = NULL;

        }//if
        else
        {
            free(obj->stackOne);
            free(obj->stackTwo);
            obj->stackOne = NULL;
            obj->stackTwo = NULL;
            free(obj);
            obj = NULL;
        }//else

    }//else


}



int main() {
    printf("Hello, World!\n");
    return 0;
}
