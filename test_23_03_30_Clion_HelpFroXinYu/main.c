#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef char STDatatype;

typedef struct Stack
{
    STDatatype* data;
    int top;
    int capacity;
}Stack;

//初始化
void STInit(Stack* p)
{
    assert(p);
    p->data = (STDatatype*)malloc(sizeof(STDatatype)*4);
    if (p->data == NULL)
    {
        perror("malloc fail");
        return;
    }
    p->top = 0;
    p->capacity = 4;

}

//销毁
void STDestory(Stack* p)
{
    assert(p);
    free(p->data);
    p->data = NULL;
    p->top = 0;
    p->capacity = 0;
}
//判空
bool STEmpty(Stack* p)
{
    assert(p);
    return p->top==0;

}

//入栈
void STPush(Stack* p, STDatatype x)
{
    if (p->top == p->capacity)
    {
        STDatatype* tmp = (STDatatype*)realloc(p->data, sizeof(STDatatype) * p->capacity * 2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        p->data = tmp;
        p->capacity *= 2;
    }
    p->data[p->top] = x;
    p->top++;
}

//出栈
void STPop(Stack* p)
{
    assert(p);
    assert(!STEmpty(p));
    p->top--;
}

//栈中元素个数
int STSize(Stack* p)
{
    assert(p);
    return p->top;
}


//返回栈顶元素
STDatatype STTop(Stack* p)
{
    assert(p);
    assert(!STEmpty(&p));
    return p->data[p->top-1];
}

bool isValid(char * s){
    assert(s);
    Stack p;
    STInit(&p);
    while(*s)
    {
        if(*s=='('||*s=='{'||*s=='[')
        {
            STPush(&p, *s);
        }
        else
        {
            if(STEmpty(&p))
            {
                STDestory(&p);
                return false;
            }
            if((*s==')'&& STTop(&p)=='(')||(*s == '}' && STTop(&p) == '{')||(*s == ']' && STTop(&p) == '['))
            {
                STPop(&p);
            }else{
                return false;
            }
        }
        s++;
    }
    if(!STEmpty(&p))
    {
        STDestory(&p);
        return false;
    }
    else
    {
        STDestory(&p);
        return true;
    }
}



int main() {
//    int i = 10;
//    if(i > 1)
//    {
//        int i = 0;
//
//        printf("%d\n",i);
//    }
//    printf("%d\n",i);
//
//    printf("%d %d",i,i++);
//    int y = 5;
//    for (; i < 1,y>3; ++i,y--) {
//
//        printf("ddd");
//    }
    char c[] = "(])";
    printf("%d\n", isValid(c));
    return 0;
}
