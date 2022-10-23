#include <stdio.h>

int main() {


    int arr[3] = {0};
    int temp = 0;


    for (int i = 0; i < 3; ++i) {
        scanf("%d",&arr[i]);

    }

    for (int i = 0; i < 2; ++i) {

        for (int j = i; j < 3; ++j) {
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }

    }

    printf("%d %d %d",arr[0],arr[1],arr[2]);
    return 0;
}
