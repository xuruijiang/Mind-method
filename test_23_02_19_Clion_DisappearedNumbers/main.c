#include <stdio.h>

int missingNumber(int* nums, int numsSize){

    int temp = 0;
    for(int i = 0; i < numsSize; ++i){

        temp ^= nums[i];
    }

    for(int i = 0; i < numsSize + 1; ++i){

        temp ^= i;
    }

    return temp;
}
int main() {

    int nums[10] = {0,1,2,3,4,5,6,7,9,10};
    printf("%d",missingNumber(nums,10));

    return 0;
}
