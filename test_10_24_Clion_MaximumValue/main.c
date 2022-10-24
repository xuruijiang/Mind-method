#include <stdio.h>

int main() {


    int arr[10] = {3,5,7,9,12,44,55,75,84,2};

    int count = arr[0];

    for (int i = 1; i < 10; ++i) {

        count = (count < arr[i])? arr[i] : count;

    }

    printf("%d\n",count);
    return 0;
}
