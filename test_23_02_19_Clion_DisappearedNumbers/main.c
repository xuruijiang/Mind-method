//#include <stdio.h>
////#include "test.h"
////测试
//int missingNumber(int* nums, int numsSize){
//
//    int temp = 0;
//    for(int i = 0; i < numsSize; ++i){
//
//        temp ^= nums[i];
//    }
//
//    for(int i = 0; i < numsSize + 1; ++i){
//
//        temp ^= i;
//    }
//
//    return temp;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int main() {
//
//
//
//    int *p;
//    int a[5] = {4,3,6,5,1};
//    p = a;
//    printf("%d ",(*p)++);
//    printf("%d",*p);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

struct T {
    int  x;
    struct T * y;
} data[2]={10, 0, 20, 0};

void main()
{



    struct T * cur;
    struct T * pre = (struct T *)malloc(sizeof(struct T));
    cur = pre;
    pre ->x = 10;
    free(pre);
    printf("%d",pre->x);

}