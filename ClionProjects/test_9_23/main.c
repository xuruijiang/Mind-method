#include <stdio.h>
#include <stdlib.h>


/*struct romm{
    char name[6];
    int age;
    float height;
    char hobbby[6];

};*/


void fun(int a){
    int *p = malloc(a*4);

    for (int i = 0; i < a; ++i) {
        scanf('%d',(p + i));
    }

    for (int i = 0; i < a; ++i) {
        printf('%d',*(p  + i));

    }

}
int main() {

    int a = 5;
    //fun(a);

    printf('%d',a);
  /*  char aa[6] = "徐江";
   //printf("%s",aa);

    struct romm r = { "徐瑞", 18,5,"羽球"};

    printf("%d",sizeof (r));
    printf("%s,%d,%f,%s",r.name,r.age,r.height,r.hobbby);

    //char a[9] = "羽毛球";
    //printf('%d',sizeof(a));*/
    return 0;
}
