// #include <stdio.h>

// int main(){

//     int a = 0;
//     printf("输入：");
//     scanf("%d",&a);
//     printf("%d\n",a);

//     return 0;
// }

#include <stdio.h>
#include <unistd.h>
typedef unsigned int u_int;
typedef int a[10];
int main() {
    char c = 0;
    char a[10] = {"abcdff"};
    printf("sizeof(c): %d\n",sizeof(c));         //1
    printf("sizeof(&c): %d\n",sizeof(&c));       //8
  	printf("sizeof(~c): %d\n",sizeof(~c));       //4
  	printf("sizeof(c): %d\n",sizeof(c << 1));    //4
  	printf("sizeof(c): %d\n",sizeof(c >> 1));    //4
    //printf("%d\n",-1 ^ -2);
//    u_int num = 0;
//    a b;
//    b[9] = 10;
//    printf("%p\n",b);
//    printf("%d\n",b[9]);

//    int /*  */ i;
//    char * c = "aada    //ss";
    //dssff \
    fsffsfff
    // in/*  */t i;  //错误

    int index = 0;

    const char * p = "|/-\\";

    while (1){
        index %= 4;
        printf("[%c]\r",p[index]);
        index++;
        sleep(1);
    }


    return 0;

}
