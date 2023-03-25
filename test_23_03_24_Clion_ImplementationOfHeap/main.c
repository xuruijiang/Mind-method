#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;

extern bool HeapEmpty(Heap*);
extern void HeapPush(Heap* ,HPDataType );
//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
    assert(hp);
    assert(a);
    hp->_a = (HPDataType *) malloc(sizeof(int));
    hp -> _capacity = 1;
    hp->_size = 0;
    for (int i = 0; i < n; ++i)
    {
        HeapPush(hp, a[i]);
    }//for

}//函数结束

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 堆的销毁
void HeapDestory(Heap* hp){

    assert(hp);
    free(hp->_a);
    hp->_a = NULL;
    hp->_size = 0;
    hp->_capacity = 0;
    free(hp);
    hp = NULL;
}

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
    assert(hp);
    HPDataType temp = 0;
    int child = 0;

    if(hp->_size == hp ->_capacity)
    {
        hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity * 2 );
        hp->_capacity = hp->_capacity * 2;
    }//if

        child = hp->_size;
        hp->_a[hp->_size] = x;
        hp->_size++;

        while(child > 0)
        {
            if(hp->_a[child] > hp ->_a[(child-1)/2])
            {
                temp = hp->_a[child];
                hp->_a[child] = hp->_a[(child-1)/2];
                hp->_a[(child-1)/2] = temp;

                child = (child-1)/2;
            }//if
            else
            {
                break;
            }//else

        }//while



}

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 堆的删除
void HeapPop(Heap* hp)
{
    assert(hp);
    if (HeapEmpty(hp))
    {
        return;
    }//if
    else
    {
        HPDataType temp = 0;
        int father = 0;
        int child = 0;
        temp = hp->_a[0];
        hp->_a[0] = hp->_a[hp->_size - 1];
        hp->_a[hp->_size] = temp;
        hp->_size--;

        while((father * 2 + 1) <= hp->_size)
        {

            if(father * 2 + 2 > hp->_size )
            {

                if ( hp->_a[father] < hp->_a[father * 2 + 1])
                {
                    temp = hp->_a[father];
                    hp->_a[father] = hp->_a[father * 2 + 1];
                    hp->_a[father * 2 + 1] = temp;
                    break;
                }//if
                else
                {
                    break;
                }//else


            }//if

            child =  (hp->_a[father * 2 + 1] > hp->_a[father * 2 + 2])? father * 2 + 1 : father * 2 + 2;

            if (hp->_a[father] <  hp->_a[child])
            {
                temp = hp->_a[father];
                hp->_a[father] = hp->_a[child];
                hp->_a[child] = temp;

                father = child;
            }//if
            else{
                break;
            }

        }//while




    }//else



}//函数结束

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
    assert(hp);

    return hp->_a[0];
}//函数结束

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 堆的数据个数
int HeapSize(Heap* hp)
{
    assert(hp);
    return hp->_size;
}//函数结束

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//
// 堆的判空
bool HeapEmpty(Heap* hp)
{
    assert(hp);
    if(hp->_size > 0)
    {
        return false;
    }//if
    else
    {
        return true;
    }//esle

}//函数结束

//-----------------------------------------------------------------------手动分割------------------------------------------------------------------------------//

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();

int main() {

    Heap heap;

     int i = HeapEmpty(&heap);
    if (i == 1)
    {
        printf("Null\n");
    }//if
    HPDataType a[10] = {3,5,7,9,12,3,5,22,34,5,};
    HeapCreate(&heap,a,10);
    HeapPop(&heap);

    for (int i = 0; i < 9; ++i) {
        printf("%d->",heap._a[i]);
    }
    return 0;
}
