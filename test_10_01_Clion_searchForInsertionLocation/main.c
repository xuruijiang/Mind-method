#include <stdio.h>


int searchInsert(int* nums, int numsSize, int target){

    if(numsSize == 0){
        return numsSize;
    }

    for (int i = 0; i < numsSize; ++i) {
        if(nums[i] == target){

            return i;
        }

        if(nums[i] > target){

            return i ;
        }

        if(i == numsSize - 1){

            return numsSize;
        }

    }

    return 0;
}
int main() {


    int arr[4] = {1,3,4,5};

    int k = searchInsert(arr,4,8);

    printf("%d\n",k);
    return 0;
}
