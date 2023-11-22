#include <stdio.h>

//int main() {
//    int a = 0;
//    int b = 0;
//    //scanf("a=%d,b=%d",&a,&b);
//
//    printf("%d,%d\n",a,b);
//
//    a = 5.6&&8.1;
//    printf("%d\n",a);
//
//    char  ch = 2;
//    int x =2;
//    float y = 2.0f;
//    double z = 2.5;
//
//    int aa = (2 - 2.5)
//
//    printf("%lf\n",aa);
//    return 0;
//}

//int main()
//{
//    int x,y;
//
//    for ( x = 1; x <= 5; ++x) {
//
//        for ( y = 1; y <= x; ++y) {
//            printf("%d*%d=%-2d ",x,y,x*y);
//        }
//
//        printf("\n");
//    }
//
//
//}

int main() {
    int c;
    while ((c = getchar())!= '\n')
        switch (c-'2') {
        case 0:
            case 1:
                putchar(c+4);
            case 2:
                putchar(c+4);break;
            case 3:
                putchar(c + 3);
        }


    return 0;
}