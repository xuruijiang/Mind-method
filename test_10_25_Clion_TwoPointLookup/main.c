#include <stdio.h>

int main() {

    int arr[10] = {3,5,7,9,12,33,45,57,68,99};

    int left = 0;
    int right = 9;
    int count = 0;
    int num = 0;
    int mid;
    scanf("%d",&count);

    for (;left < right - 1;) {

        mid = (left+right)/2;
        if(arr[mid] == count){
            num = 1;
            printf("找到了:%d\n",mid);
            break;
        } else if(arr[mid] > count){

            right = mid;
        } else{

            left = mid;
        }

    }

    if(0 == num){
        printf("没找到\n");
    }
    return 0;
}
