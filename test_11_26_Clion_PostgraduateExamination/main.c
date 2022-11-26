#include <stdio.h>

int main() {


//    int a = 0;
//    int b = 0;
//    FILE *p = fopen("/Users/xuruijiang/Desktop/date.txt","w");
//
//    fputc('a',p);
//    fputc(' ',p);
//    fputc('b',p);


        char arr[] = "abcdef";


        char * p = arr;
        printf("%c\n",*p++);
        printf("%c\n",*++p);

    return 0;
}
