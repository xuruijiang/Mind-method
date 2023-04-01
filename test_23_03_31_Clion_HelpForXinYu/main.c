#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
    int size;
}Queue;

//初始化
void QueueInit(Queue* p)
{
    assert(p);
    p->head = p->tail = NULL;
    p->size = 0;
}

//销毁
void QueueDestory(Queue* p)
{
    assert(p);
    QNode* cur = p->head;
    if (p->head == NULL)
    {
        return;
    }
    if (p->head==p->tail)
    {
        free(p->head);
        p->head = p->tail = NULL;
        p->size = 0;
    }
    else
    {
        QNode* next = cur->next;
        while (cur)
        {
            free(cur);
            cur = cur->next;
        }
        p->head = p->tail = NULL;
        p->size = 0;
    }

}

//入队
void QueuePush(Queue* p, QDataType x)
{
    assert(p);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    if (p->head == NULL)
    {
        assert(p->head == p->tail);
        p->head = p->tail = newnode;
    }
    else
    {
        p->tail->next = newnode;
        p->tail = p->tail->next;
    }
    p->size++;
}

//出队
void QueuePop(Queue* p)
{
    assert(p);
    assert(p->head != NULL);
    QNode* cur = p->head;
    if (p->head != p->tail)
    {
        cur = cur->next;
        free(p->head);
        p->head = cur;
        p->size--;
    }
    else
    {
        free(p->tail);
        p->head = p->tail = NULL;
        p->size--;
    }
}

//队中元素个数
int QueueSize(Queue* p)
{
    assert(p);
    return p->size;
}

//判空
bool QueueEmpty(Queue* p)
{
    assert(p);
    return p->size==0;
}

//队头元素
QDataType QueueFront(Queue* p)
{
    assert(p);
    assert(!QueueEmpty(p));
    return p->head->data;
}

//队尾元素
QDataType QueueBack(Queue* p)
{
    assert(p);
    assert(!QueueEmpty(p));
    return p->tail->data;
}



typedef struct {
    Queue a;
    Queue b;
} MyStack;


MyStack* myStackCreate() {
    MyStack* ptsd=(MyStack*)malloc(sizeof(MyStack));
    if(ptsd==NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    QueueInit(&ptsd->a);
    QueueInit(&ptsd->b);
    return ptsd;
}

void myStackPush(MyStack* obj, int x) {
    //assert(ptsd);
    if(!QueueEmpty(&obj->a))
    {
        QueuePush(&obj->a, x);
    }
    else
    {
        QueuePush(&obj->b, x);
    }
}

int myStackPop(MyStack* obj) {
    //assert(obj);
    //assert(!(QueueEmpty(&obj->a)&&QueueEmpty(&obj->b)));
    Queue QEmpty=obj->a;
    Queue QNEmpty=obj->b;
    if(QueueEmpty(&obj->b))
    {
         QEmpty=obj->b;
         QNEmpty=obj->a;
    }
    while(QueueSize(&QNEmpty)>1)
    {
        QueuePush(&QEmpty, QueueFront(&QNEmpty));
        QueuePop(&QNEmpty);
    }
    int ret=QueueFront(&QNEmpty);
    QueuePop(&QNEmpty);
    return ret;

}

int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&obj->a))
    {
        return QueueBack(&obj->a);
    }
    else
    {
        return QueueBack(&obj->b);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->a)&&QueueEmpty(&obj->b);
}

void myStackFree(MyStack* obj) {
    QueueDestory(&obj->a);
    QueueDestory(&obj->b);
    free(obj);

}



int main() {

    MyStack *p = myStackCreate();
    myStackPush(p,3);
    myStackPush(p,4);
    myStackPush(p,5);
    //myStackPop(p);
    printf("%d\n", myStackTop(p));
    printf("%d\n", myStackEmpty(p));
    myStackPop(p);
    myStackPop(p);
    printf("%d\n", myStackEmpty(p));

    return 0;
}
