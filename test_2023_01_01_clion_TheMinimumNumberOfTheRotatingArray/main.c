#include <stdio.h>


int minNumberInRotateArray(int* rotateArray, int rotateArrayLen ) {


    for(int i = 1; i < rotateArrayLen; i++){
        if( *rotateArray > *(rotateArray + i)){
            return *(rotateArray + i);
        }
    }

    return *rotateArray;
}

int main() {


    int arr[5] = {3,4,5,1,2};

    int min = minNumberInRotateArray(arr,sizeof(arr)/sizeof(arr[0]));
    printf("%d\n",min);
    return 0;
}
