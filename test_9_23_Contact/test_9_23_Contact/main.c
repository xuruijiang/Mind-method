//#include<stdio.h>
//#include <stdlib.h>
//
// struct P{
//    char name[6];
//    int age;
//    char happy[6];
// }p;
//
//
////#define M 10
//int main(){
//
////    const int M = 10;
////    int a[M] = {0};
////
////    for (int i =0; i < M; i++) {
////        printf("%d,",a[i]);
////    }
//
////    char arr[5] = "abcde";
//
//    //char aa = 0x7C;
//    //printf("%c\n",aa);
////    *(arr + 5) = 0;
////    *(arr + 6) = 98;
////    printf("%s\n",arr);
////    int a = 0;
//
////    int *p =(int *) malloc(0);
////
////    printf("%p\n",p);//不是返回空指针
////    char arr[10] = "bcd";
////    printf("%s\n",arr);
////    *arr = NULL;
////
////    if(*(arr) == NULL ){
////
////        printf("hehe");
////    }
////    return 0;
//
//
////    struct P p = {"徐",18,"羽"};
////
////    scanf("%s",p.name);
////    printf("%s\n",p.name);
//
////    struct P * pp = &p;
////
////    for (int i =65; i<75;i++) {
////        *(char *)pp = i;
////    }
//       // p = (struct P *) malloc(sizeof(struct P));
//
////    char a[] = "123";
////
////    int b =  atol(a);
////    printf("%d\n",b);
//
////    printf("%p\n",p.name);
////    printf("%c\n",*((char *)p.name + 6));
////    printf("%p\n",&(p.age));
////    printf("%p\n",p.happy);
////        printf("%s\n",p.name);
//
////    int a = 2000000000;
////    printf("%d\n",a);
//
//
////    char arr[10];
////
////    scanf("%s",arr);
////    printf("%s\n",arr);
//
////    char a = 380;
////    printf("%c\n",a);
//    return 0;
//
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    int arr[100000] = {0};
    char arc[1000][10];
    int count = 0;
    int a, i, k;

    while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
        // 64 位输出请用 printf("%lld")
        //printf("%d\n", a + b);

        for (i = 0; i < a; ++i) {
            gets(arc[i]);

        }


        for (i = 0; i < a; ++i) {

            if (arc[i][0] == 'p' && arc[i][1] == 'u') {

                for (k = 0; k < count; ++k) {
                    arr[count - k]  = arr[count - k - 1];


                }
                arr[count] = atol( arc[i] + 4);
                count++;



            } else if (arc[i][0] == 't') {

                if (count > 0) {
                    printf("%d\n", arr[0]);
                } else {
                    printf("error\n");
                }


            } else {

                if (count > 1) {
                    for (k = 0; k < count; ++k) {
                        arr[k]  = arr[k + 1];

                    }

                    arr[count - 1] = 0;
                    count--;

                    printf("%d\n", arr[0]);

                } else if ( count == 1) {

                    arr[0] = 0;

                    count--;

                } else {
                    printf("error\n");
                }


            }
        }


    count = 0;

    }
    return 0;
}
