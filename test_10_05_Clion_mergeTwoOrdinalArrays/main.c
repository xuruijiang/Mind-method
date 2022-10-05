#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int *p = (int *) malloc(nums1Size * sizeof(nums1));
    int countOne = 0;
    int countTwo = 0;

    int i = 0;
    while (countOne < m && countTwo < n) {
        if (*(nums1 + countOne) < *(nums2 + countTwo)) {
            p[i] = *(nums1 + countOne);
            countOne++;
        } else{
            p[i] = *(nums2 + countTwo);
            countTwo++;
        }

        i++;
    }

    while (countOne < m) {
        p[i] = *(nums1 + countOne);
        i++;
        countOne++;

    }

    while (countTwo < n) {
        p[i] = *(nums2 + countTwo);
        i++;
        countTwo++;

    }

    for (int j = 0; j < nums1Size; ++j) {

        nums1[j] = p[j];
    }

}

int main() {


    int num1[6] = {1,2,3,0,0,0};
    int num2[3] = {2,5,6};
    merge(num1,6,3,num2,3,3);

    for (int i = 0; i < 6; ++i) {
        printf("%d,",num1[i]);
    }
    return 0;
}
