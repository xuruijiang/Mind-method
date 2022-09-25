#include <stdio.h>
#include <assert.h>
#include <string.h>


void* my_memcpy(void* dest,const void* src,size_t num){
    assert(dest && src);
    void* destptr = dest;


    for (int i = 0; i < num; ++i) {
        *((char*) dest) =  *((char*) src);
        dest = (char *)dest + 1;//((char*)dest)++ 此法不行，有的编译器跑不了。
        src = (char *)src + 1;
    }

    return destptr;
}

int main() {

   /* int a[12]={1,2,3,4,5,6,7,8,9,10,11,12}, *p[4],i;
    for(i=0;i<4;i++)
        p[i]=&a[i*3];
    printf("%d\n",p[3][2]);*/

    /*char s[20]="abcd",*p2="ABCD",str[50]="xyz";
    strcpy(str+2, strcat(s+2,p2+1));
    printf("%s\n", str);
    return 0;*/

    /*int a=7;
    double x=2.5,y=4.7;
    printf("%f\n",x+a%3*(int)(x+y)%2/4);
*/

    /*int i;
    char *s= "abcd";
    for ( i=0 ; i<strlen(s); i++)
        printf ("%s\n" ,s+i );
    return 0;*/

    /*int a=5,b=7;
    printf("%d\n",(a=3)&&(b=-3));*/

    /*char a[] = "abc";
    char b[] = "aba";

    printf("%d\n",strcmp(a,b));*/ //strcmp比较两个字符串的时候，返回值是前面字符减后面字符；

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {0};

    my_memcpy(arr2,arr1,20);
    //memcpy(arr1 + 2,arr1,20);//所以memcpy不能拷贝重叠的内存，改用memmove
    //memmove(arr1 + 2,arr1,20);
    for (int i = 0; i < 10; ++i) {
        printf("%d,",arr2[i]);
    }

    return 0;
}
