#include <stdio.h>
void rotate(int* nums, int numsSize, int k){

    int temp = 0;
    for(int i = 0; i < k / 2; ++i){
        temp = nums[i];
        nums[i] = nums[k - i - 1];
        nums[k - i - 1] = temp;
    }

    for(int i = k; i < (numsSize - k)/2 + k;++i){
        temp = nums[i];
        nums[i] = nums[numsSize - 1 + k -i];
        nums[numsSize - 1 + k - i] = temp;
    }

    for(int i = 0; i < numsSize / 2; ++i){

        temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 -i] = temp;
    }
}
int main() {

    int nums[9] = [1,2,3,4,5,6,7,8,9];
    rotate(nums,9,4);
    for (int i = 0; i < 9; ++i) {
        printf("%d ",nums[i]);
    }
    printf("aaa");
    return 0;
}
