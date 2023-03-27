#include <stdio.h>

// 对数组进行堆排序
void HeapSort(int* a, int n) {
    int number = n - 1;
    int father = number;
    int temp = 0;
    int child = 0;
    for (int i = n - 1; i >= 0; i--) {
        father = i;
        while ((father * 2 + 1) <= n - 1) {
            if (father * 2 + 1 <= n - 1) {
                if (father * 2 + 2 > n - 1) {
                    if (a[father] < a[father * 2 + 1]) {
                        temp = a[father];
                        a[father] = a[father * 2 + 1];
                        a[father * 2 + 1] = temp;
                        break;
                    }//if
                    else {
                        break;
                    }//else
                }//if


            }//if

            child = (a[father * 2 + 1] > a[father * 2 + 2]) ? father * 2 + 1 : father * 2 + 2;

            if (a[father] < a[child]) {
                temp = a[father];
                a[father] = a[child];
                a[child] = temp;

                father = child;
            }//if
            else {
                break;
            }

        }//while


    }//for


}//函数结束


int main() {
    int a[10] = {4,6,2,78,33,2,14,98,43,12};
    HeapSort(a,10);
    for (int i = 0; i < 10; ++i) {

        printf("%d ",a[i]);
    }
    return 0;
}
