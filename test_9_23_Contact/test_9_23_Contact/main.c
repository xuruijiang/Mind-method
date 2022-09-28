////#include<stdio.h>
////#include <stdlib.h>
////
//// struct P{
////    char name[6];
////    int age;
////    char happy[6];
//// }p;
////
////
//////#define M 10
////int main(){
////
//////    const int M = 10;
//////    int a[M] = {0};
//////
//////    for (int i =0; i < M; i++) {
//////        printf("%d,",a[i]);
//////    }
////
//////    char arr[5] = "abcde";
////
////    //char aa = 0x7C;
////    //printf("%c\n",aa);
//////    *(arr + 5) = 0;
//////    *(arr + 6) = 98;
//////    printf("%s\n",arr);
//////    int a = 0;
////
//////    int *p =(int *) malloc(0);
//////
//////    printf("%p\n",p);//不是返回空指针
//////    char arr[10] = "bcd";
//////    printf("%s\n",arr);
//////    *arr = NULL;
//////
//////    if(*(arr) == NULL ){
//////
//////        printf("hehe");
//////    }
//////    return 0;
////
////
//////    struct P p = {"徐",18,"羽"};
//////
//////    scanf("%s",p.name);
//////    printf("%s\n",p.name);
////
//////    struct P * pp = &p;
//////
//////    for (int i =65; i<75;i++) {
//////        *(char *)pp = i;
//////    }
////       // p = (struct P *) malloc(sizeof(struct P));
////
//////    char a[] = "123";
//////
//////    int b =  atol(a);
//////    printf("%d\n",b);
////
//////    printf("%p\n",p.name);
//////    printf("%c\n",*((char *)p.name + 6));
//////    printf("%p\n",&(p.age));
//////    printf("%p\n",p.happy);
//////        printf("%s\n",p.name);
////
//////    int a = 2000000000;
//////    printf("%d\n",a);
////
////
//////    char arr[10];
//////
//////    scanf("%s",arr);
//////    printf("%s\n",arr);
////
//////    char a = 380;
//////    printf("%c\n",a);
////    return 0;
////
////}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main() {
//
//    int arr[100000] = {0};
//    char arc[1000][10];
//    int count = 0;
//    int a, i, k;
//
//    while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
//        // 64 位输出请用 printf("%lld")
//        //printf("%d\n", a + b);
//
//        for (i = 0; i < a; ++i) {
//            gets(arc[i]);
//
//        }
//
//
//        for (i = 0; i < a; ++i) {
//
//            if (arc[i][0] == 'p' && arc[i][1] == 'u') {
//
//                for (k = 0; k < count; ++k) {
//                    arr[count - k]  = arr[count - k - 1];
//
//
//                }
//                arr[count] = (int)atol( arc[i] + 5);
//                count++;
//
//
//
//            } else if (arc[i][0] == 't') {
//
//                if (count > 0) {
//                    printf("%d\n", arr[0]);
//                } else {
//                    printf("error\n");
//                }
//
//
//            } else {
//
//                if (count > 1) {
//                    for (k = 0; k < count; ++k) {
//                        arr[k]  = arr[k + 1];
//
//                    }
//
//                    arr[count - 1] = 0;
//                    count--;
//
//                    printf("%d\n", arr[0]);
//
//                } else if ( count == 1) {
//
//                    arr[0] = 0;
//
//                    count--;
//
//                } else {
//                    printf("error\n");
//                }
//
//
//            }
//        }
//
//
//    count = 0;
//
//    }
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solve(char *s, char *t ) {
    // write code here

    int t_lenth,s_lenth;
    int count = 0;
    int count2 = 0;
    char sum[100];
    int m = 0,i = 0;

    s_lenth = (int)strlen(s);
    t_lenth = (int)strlen(t);

    int lenth = s_lenth>t_lenth? s_lenth:t_lenth;

    for ( i = 0; i < lenth; ++i) {


        if ((s_lenth - 1 -i) >= 0 &&  (t_lenth - 1 -i) >= 0){

            char a = *(s + s_lenth - 1 - i) ;
            char b = *(t + t_lenth - 1 - i);

            if ( (m = ((a - 48) + (b - 48) + count)) >= 10){
                sum[i] = (char)((m % 10) + 48);
                count2++;
                count = 1;
            }else{
                sum[i] = (char)(m + 48);
                count2++;
                count = 0;

            }

        }else if ((s_lenth - 1 -i) <0){
            
            if((*(t + t_lenth - 1 - i)  + count -48) >= 10 ){
                sum[i] = (char)(((*(t + t_lenth - 1 - i)  + count -48)%10) +48);
                count2++;
                count = 1;
            }else{
                sum[i] = (char)(*(t + t_lenth - 1 - i)  + count);
                count = 0;
            }
           
            

        } else if ((t_lenth - 1 -i) <0){
            
            if((*(s + s_lenth - 1 - i)  + count -48) >= 10 ){
                sum[i] = (char)(((*(s + s_lenth - 1 - i)  + count -48)%10) +48);
                count2++;
                count = 1;
            }else{
                sum[i] = (char)(*(s + s_lenth - 1 - i)  + count);
                count = 0;
            }
        }



    }
    
    if(count == 1){
        
        sum[i] = '1';
        count2++;
    }
    

    for (int i = 0; i < count2; ++i) {

        *(t + i) = sum[count2 - i - 1] ;

    }



    return t;

}
int main() {

    /*char* p = "173890333";

    char a = *(p + 2);


    printf("%d",*(p + 2) - 48);*/

    char slenth[100];
    char tlenth[100];

    scanf("%s %s",slenth,tlenth);

    solve(slenth,tlenth);
    printf("%s\n",tlenth);

    return 0;
}
