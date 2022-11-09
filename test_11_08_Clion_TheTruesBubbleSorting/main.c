#include <stdio.h>

void sort(int *p,int n){

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if(p[j] > p[j + 1]){

                p[j] = p[j + 1] ^ p[j];
                p[j + 1] = p[j + 1] ^ p[j];
                p[j] = p[j + 1] ^ p[j];
            }

        }
    }


}
int main() {

    int arr[10] = {2,4,8,5,3,1,9,6,7,0};
    sort(arr,sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {

        printf("%d ",arr[i]);
    }
    return 0;
}
