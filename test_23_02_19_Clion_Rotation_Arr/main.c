#include <stdio.h>
void rotate(int* nums, int numsSize, int k){

    k = k % numsSize;
    int temp = 0;
    for(int i = 0; i < (numsSize - k) / 2; ++i){
        temp = nums[i];
        nums[i] = nums[numsSize - k - 1 - i];
        nums[numsSize - k - 1 - i] = temp;
    }

    for(int i = numsSize - k; i < k/2 + numsSize - k;++i){
        temp = nums[i];
        nums[i] = nums[numsSize - 1 + numsSize - k - i];
        nums[numsSize - 1 + numsSize - k - i] = temp;
    }

    for(int i = 0; i < numsSize / 2; ++i){

        temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 -i] = temp;
    }
}
int main() {

    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    rotate(nums,10,5);
    for (int i = 0; i < 10; ++i) {
        printf("%d ",nums[i]);
    }
    printf("aaa");
    return 0;
}
