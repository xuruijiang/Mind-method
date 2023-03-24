#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
typedef struct {
    int * list;
    int front;
    int rear;
    int Capacity;
} MyCircularQueue;

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//判断队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    if(obj == NULL || obj -> list == NULL  )
    {
        return false;
    }//if
    else
    {
        if(obj->front == obj->rear)
        {
            return true;
        }//if
        else
        {
            return false;
        }//else
    }//else

}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//创建我的循环队列
MyCircularQueue* myCircularQueueCreate(int k)
{

    MyCircularQueue *myCircularQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    myCircularQueue->list = (int *) malloc(sizeof(int) * (k+1));
    myCircularQueue->front = 0;
    myCircularQueue->rear = 0;
    myCircularQueue->Capacity = k + 1;

    return myCircularQueue;
}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//入队列 成功返回真
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if(obj == NULL || obj -> list == NULL  )
    {
        return false;
    }//if
    else
    {
        if( (obj->rear + 1)% obj->Capacity == obj->front )
        {
            return false;
        }//if
        else
        {
            (obj->list)[obj->rear] = value;
            obj->rear = (obj->rear + 1) % obj->Capacity;
            return true;

        }//else
    }//else

}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//出队列 成功返回真
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if(obj == NULL || obj -> list == NULL  )
    {
        return false;
    }//if
    else
    {
        if (myCircularQueueIsEmpty(obj))
        {
            return false;
        }//if
        else
        {
            obj->front = (obj->front + 1) % obj->Capacity;
            return true;
        }//else
    }//else


}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//查看队头数据
int myCircularQueueFront(MyCircularQueue* obj)
{
    if(obj == NULL || obj -> list == NULL  )
    {
        return NULL;
    }//if
    else
    {
        if(myCircularQueueIsEmpty(obj))
        {
           return NULL;
        }//
        else
        {
           return obj->list[obj->front];
        }//
    }//else

}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//查看队尾数据
int myCircularQueueRear(MyCircularQueue* obj)
{
    if(obj == NULL || obj -> list == NULL  )
    {
        return NULL;
    }//if
    else
    {
        if(myCircularQueueIsEmpty(obj))
        {
            return NULL;
        }//if
        else
        {
           if(obj->rear == 0)
           {
               return obj->list[obj->list[obj->Capacity-1]];
           }//if
           else
           {
               return obj->list[obj->rear-1];
           }//else
        }//else
    }//else

}//函数结束


//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//判断队列是否是满的
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    if(obj == NULL || obj -> list == NULL  )
    {
        return NULL;
    }//if
    else
    {
        if((obj->rear + 1)% obj->Capacity == obj->front)
        {
            return true;
        }//if
        else
        {
            return false;
        }//else
    }//else
}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
//销毁队列
void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->list);
    obj->list =NULL;
    free(obj);
    obj = NULL;
}//函数结束

//----------------------------------------------------------手动分割--------------------------------------------------------------------//
int main() {


    MyCircularQueue *myCircularQueue = myCircularQueueCreate(10);

    myCircularQueueEnQueue(myCircularQueue,3);
    myCircularQueueEnQueue(myCircularQueue,1);
    myCircularQueueEnQueue(myCircularQueue,2);
    myCircularQueueEnQueue(myCircularQueue,3);
    myCircularQueueEnQueue(myCircularQueue,4);
    myCircularQueueEnQueue(myCircularQueue,6);
    myCircularQueueEnQueue(myCircularQueue,7);
    myCircularQueueDeQueue(myCircularQueue);
    myCircularQueueDeQueue(myCircularQueue);
    myCircularQueueDeQueue(myCircularQueue);
    printf("%d\n", myCircularQueueFront(myCircularQueue));
    printf("%d\n", myCircularQueueRear(myCircularQueue));
    return 0;
}
