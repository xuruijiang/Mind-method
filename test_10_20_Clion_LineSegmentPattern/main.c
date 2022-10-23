#include <stdio.h>

int fnuc(int a){

    int b;
    switch (a)
    {
        case 1: b = 30;
        case 2: b = 20;
        case 3: b = 16;
        default: b = 0;
    }
    return b;


}

int main() {

//    int count = 0;
//
//    while (scanf("%d",&count) != EOF){
//
//        for (int i = 0; i < count; ++i) {
//
//            printf("*");
//        }
//
//        printf("\n");
//    }


    int num = fnuc(1);

    printf("%d\n",num);

    return 0;
}
