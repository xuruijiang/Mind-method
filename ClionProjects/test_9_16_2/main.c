#include <stdio.h>
#include <string.h>

struct B{
    char a;
    int b;
    char c;

};
struct S{
    char a;
    struct B b;
    int c;

};






int main() {


    /*char ac[] = "aaaaa";
    printf("%d\n",sizeof (ac));*/
    struct B b = {0};

    struct S s = {0};

    //printf("%d\n",sizeof (b));

    char *p1 = (char*)&b;
    char *p2 = (char*)&(b.a);
    char *p3 = (char*)&(b.b);
    char *p4 = (char*)&(b.c);

    printf("%d,",p2 - p1);
    printf("%d,",p3 - p1);
    printf("%d,",p4 - p1);



    return 0;
}
