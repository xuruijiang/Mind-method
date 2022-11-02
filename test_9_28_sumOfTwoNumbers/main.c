#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersLen, int target, int* returnSize ) {

    int j = 0;
    *returnSize = 2;
    int* p = (int*)malloc(2 * sizeof(int));
    for (int i = 1; i < numbersLen; ++i) {

        if (numbers[j] > target && (j < numbersLen - 1)) {

            j++;
            i = j;
            continue;
        }

        if ((numbers[i] + numbers[j] == target)) {

            p[0] = (i < j) ? i + 1 : j + 1;
            p[1] = (i > j) ? i + 1 : j + 1;
            return p;
        } else if (i == (numbersLen - 1)) {

            j++;
            i = j;
        }
    }

    return p;
}

int main() {

    int arr[3] = {3,2,4};
    int sum = 7;
    int returnSize = 0;
    int *ptr = twoSum(arr,3,sum,&returnSize);

    printf("[%d,%d]\n",ptr[0],ptr[1]);
    free(ptr);
    ptr = NULL;

    return 0;
}
