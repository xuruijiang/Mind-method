/*
#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int choose = 0;

    for(int i = 0; i < numsSize ;i++){

        for(int j = 0; j < numsSize; j++){

            if(j == i){
                continue;
            }

            if( *(nums + i) + *(nums + j) == target){

                *(returnSize) = i;
                *(returnSize + 1) = j;
                choose = 1;
                break;


            }
        }

        if(choose){
            break;
        }

    }

    return returnSize;


}
int main() {

    char a[10][10] = {"push123"};

    int b =  atol(a[0] + 4);
    printf("%d\n",b);

    printf("输入几位数？:");
    int num =0;
    scanf("%d",&num);
    int *p = (int *)malloc(num * sizeof(int ));

    for (int i = 0; i < num; ++i) {
        scanf("%d",(p + i));
    }

    printf("输入目标值:");
    int  target = 0;
    scanf("%d",&target);

    int arr[2] = {0};
    twoSum(p,num,target,arr);

    if ( arr[1] ){
        printf("[%d,%d]",arr[0],arr[1]);

    }

    free(p);
    p = NULL;
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    int arr[100000] = {0};
    char arc[1000][10];
    int count = 0;
    int a, i, j, k;

    while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
        // 64 位输出请用 printf("%lld")
        //printf("%d\n", a + b);

        for (i = 0; i < a; ++i) {

            gets(arc[i]);
        }


        for (i = 0; i < a; ++i) {

            if (arc[i][0] == 'p' && arc[i][1] == 'u') {

                for (k = 0; k < count; ++k) {
                    arr[count - k]  = arr[count - k - 1];


                }
                arr[count] = atol( arc[i] + 4);
                count++;



            } else if (arc[i][0] == 't') {

                if (count > 0) {
                    printf("%d\n", arr[0]);
                } else {
                    printf("error\n");
                }


            } else {

                if (count > 1) {
                    for (k = 0; k < count; ++k) {
                        arr[k]  = arr[k + 1];

                    }

                    arr[count - 1] = 0;
                    count--;

                    printf("%d\n", arr[0]);

                } else if ( count == 1) {

                    arr[0] = 0;

                    count--;

                } else {
                    printf("error\n");
                }


            }
        }


        count = 0;

    }
    return 0;
}
