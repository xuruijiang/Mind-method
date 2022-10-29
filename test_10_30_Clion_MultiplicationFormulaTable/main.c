#include <stdio.h>

int multiplication(int n){

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= i; ++j) {

            printf("%2d * %2d = %3d  ",i,j,i*j);
        }

        printf("\n");
    }

}
int main() {


    int n = 0;
    scanf("%d",&n);

    int a = multiplication(n);
    printf("%d\n",a);

    return 0;
}
