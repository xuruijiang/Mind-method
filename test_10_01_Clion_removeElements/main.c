#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){


    for (int i = 0; i < numsSize; ++i) {

        if(nums[i] == val){
            nums[i] = nums[numsSize -1];
            numsSize--;
            i--;
        }

    }
    return numsSize;

}
int main() {


    int nums[4] = {3,2,2,3};

    int k = removeElement(nums,4,3);

    for (int i = 0; i < k; ++i) {
        printf("%d,",nums[i]);
    }

    return 0;
}
