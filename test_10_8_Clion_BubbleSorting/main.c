#include <stdio.h>

void sorting(int *p,int n ){

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            if(p[i] < p[j]){
                p[i] = p[i] ^ p[j];
                p[j] = p[i] ^ p[j];
                p[i] = p[i] ^ p[j];
            }

        }

    }

}

int main() {

    int arr[10] = {3,5,7,2,9,1,6,0,10,4};
    sorting(arr,sizeof(arr)/sizeof(int));

    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
