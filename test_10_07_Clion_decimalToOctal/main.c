//
//  main.c
//  test_10_07_Xcode_decimalToOctal
//
//  Created by 徐瑞江 on 2022/10/7.
//

#include <stdio.h>
#include <math.h>
#define M 365*24*60*60
void fun(int *p){

    int num = 0;
    int a[20] = {0} ;

    for (int i = 0; i < 5; i++) {
        int j = 0;
        num = p[i];
        p[i] = 0;
        while (1) {
            a[j] = num%8;
            num = num/8;
            j++;
            if(num == 0){
                break;
            }

        }

        for (int k = 0; k < j; ++k) {
            p[i] += a[k] * pow(10,k);

            a[k] = 0;
        }


    }




}
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5] = {0};

  /*  for (int i = 0; i < 5; ++i) {
        scanf("%d",&arr[i]);
    }

    fun(arr);
    for (int k = 0; k < 5; ++k) {

        printf("%d ",arr[k]);
    }
*/
    int a = 1101;
    int b = 1010;

    printf("%d\n",M);


    return 0;
}

