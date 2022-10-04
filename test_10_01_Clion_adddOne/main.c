#include <stdio.h>
#include <stdlib.h>


int* plusOne(int* digits, int digitsSize, int* returnSize){

    int *p = (int *) malloc((digitsSize+1)*sizeof(int));

    int count = 0;
    if (digits[digitsSize - 1] != 9){

        *returnSize = digitsSize;
        for (int i = 0; i < digitsSize; ++i) {

            p[i] = digits[i];
        }

        p[digitsSize - 1]++;
        return p;

    } else{
        count = 1;
        p[digitsSize] = 0;
        for (int i = 1; i < digitsSize; ++i) {
            if (digits[digitsSize - 1 -i] + count > 9){

                p[digitsSize - i] = 0;
                count = 1;

            } else{

                p[digitsSize - i] = digits[digitsSize - 1 -i] + count;
                count = 0;
            }



        }

        if (count == 1){
            p[0] = 1;
            *returnSize = digitsSize + 1;
        }

        if(p[0] == 0){

            *returnSize = digitsSize;
            for (int i = 0; i < digitsSize; ++i) {

                p[i] = p[i + 1];
            }
        }


    }


    return p;

}
int main() {


    int arr[] = {8,9,9,8,9,6,4,9};

    int k = 0;
    int *p;
    p = plusOne(arr, 8, &k);

    for (int i = 0; i < k; ++i) {
        printf("%d,",p[i]);
    }

    free(p);


    return 0;
}
