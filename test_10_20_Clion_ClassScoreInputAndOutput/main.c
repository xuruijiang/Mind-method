#include <stdio.h>

int main() {


    double arr[5][6] = {0};

    for (int i = 0; i < 5; ++i) {

        for (int j = 0; j < 5; ++j) {

            scanf("%lf",&arr[i][j]);
        }
    }


    for (int i = 0; i < 5; ++i) {

        for (int j = 0; j < 5; ++j) {

            arr[i][5] += arr[i][j];
        }
    }

    for (int i = 0; i < 5; ++i) {

        for (int j = 0; j < 6; ++j) {

                printf("%.1lf ",arr[i][j]);

        }
        printf("\n");
    }




    return 0;
}