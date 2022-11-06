#include <stdio.h>

int main() {

    int n = 0;
    scanf("%d",&n);

    for (int i = 1; i <= 2*n -1; ++i) {
        for (int j = 1; j <= 2*n-1; ++j) {
            if(i > n ){
                if(j <= i){
                    printf("%3d ",((2*n -i)<j)? (2*n -i):j );

                } else{
                    printf("%3d ",2*n -j);
                }

            } else{
                if(2*n  - j > i){
                    printf("%3d ",(i < j)? i:j);

                }else{
                    printf("%3d ",2*n - j);

                }
            }

        }

        printf("\n");
    }


    return 0;
}
