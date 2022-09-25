#include <stdio.h>
#include <string.h>


int Add(int a,int b){

    return a+b;
}

/*struct Test{
    int Num;
    char* pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}*p;*/
int main() {
   /* int arr[10] = {1,2,3,4,5,6,7,8,9,10};


    int (*p)[10] = &arr;
    int *pInt = arr;

    printf("%d\n",(*p)[1]);
    printf("%d\n",*pInt);
    printf("%p\n",(p+1));
    printf("%p\n",(pInt+1));*/


  /* int (*p)(int,int) = &Add;//函数指针变量；p == Add 所以调用也可以写成p(1,2)*/

  //char *a = "123456";
  //char str[10] = {"123456"};

    /*char s[ ]="12012";
    printf("%d,%d\n",sizeof(s),strlen(s) ); 6,5*/

    /*printf("%d",strcmp("abcdef","ABCDEF"));1 */

    /*int a[5] = {1,2,3,4,5};*/

    /*printf("%d\n",345/100);

    int a = 9,b = 6, c = 3;

    printf("%d",a>b>c); 0*/


    /*char str[80] = "abcdefGGG";

    char *p = str;

    printf("%c",*p);*/


    //sizeof(数组名) - 数组名表示整个数组的-计算的是整个数组的大小。
    //&数组名 - 数组名表示整个数组，取出的是整个数组的地址。
    //除此之外，所有的数组名都是数组首元素地址
   /* int a[] = {1,2,3,4};*/

    /*printf("%d\n",sizeof (a));//计算的是整个数组的大小。
    printf("%d\n",sizeof (a + 0 ));//第一个元素的地址大小，32-4， 64-8
    printf("%d\n",sizeof (*a));//计算的是第一个元素的大小
    printf("%d\n",sizeof (a + 1));//第二个元素的地址大小，32-4， 64-8
    printf("%d\n",sizeof (a[1]));//计算的是第二个元素的大小

    printf("%d\n",sizeof (&a));//8
    printf("%d\n",sizeof (*&a));//16
    printf("%d\n",sizeof (&a + 1));//8
    printf("%d\n",sizeof (&a[0]));//8
    printf("%d\n",sizeof (&a[0] + 1));//8*/



    //sizeof(arr),只有当arr为字符串时，计算的才是字符数+1；即将\0算入
  /*  char arr[] = {'a','b','c','d','e','f'};

    printf("%d\n",sizeof (arr));//6
    printf("%d\n",sizeof (arr + 0));//8
    printf("%d\n",sizeof (*arr));//1
    printf("%d\n",sizeof (arr[1]));//1
    printf("%d\n",sizeof (&arr));//8
    printf("%d\n",sizeof (&arr + 1));//8
    printf("%d\n",sizeof (&arr[0] + 1));//8*/

   /* char arr[] = {'a','b','c','d','e','f'};*/


    //strlen()里面传地址
   /* printf("%d\n", strlen(arr));//随机值
    printf("%d\n", strlen(arr+0));//随机值
    printf("%d\n", strlen(*arr));//出错
    printf("%d\n", strlen(arr[1]));//出错
    printf("%d\n", strlen(&arr));//随机值
    printf("%d\n", strlen(&arr+1));//随机值-6
    printf("%d\n", strlen(&arr[0]+1));//随机值-1*/

  /*  char arr[] = "abcdef";
    printf("%d\n",sizeof (arr));//7
    printf("%d\n",sizeof (arr + 0));//8
    printf("%d\n",sizeof (*arr));//1
    printf("%d\n",sizeof (arr[1]));//1
    printf("%d\n",sizeof (&arr));//8
    printf("%d\n",sizeof (&arr + 1));//8
    printf("%d\n",sizeof (&arr[0] + 1));//8*/
/*
    char arr[] = "abcdef";

    printf("%d\n", strlen(arr));//6
    printf("%d\n", strlen(arr + 0));//6
    printf("%d\n", strlen(*arr));//err
    printf("%d\n", strlen(arr[1]));//err
    printf("%d\n", strlen(&arr));//6
    printf("%d\n", strlen(&arr + 1));//随机值
    printf("%d\n", strlen(&arr[0] + 1));//5*/



   /* char* p = "accdef";

    printf("%d\n",sizeof (p));//8
    printf("%d\n",sizeof (p+1));//8
    printf("%d\n",sizeof (*p));//1
    printf("%d\n",sizeof (p[0]));//1
    printf("%d\n",sizeof (&p));//8
    printf("%d\n",sizeof (&p + 1));//8
    printf("%d\n",sizeof (&p[0] + 1));//8*/


 /*   char* p = "accdef";

    printf("%d\n", strlen(p));//6
    printf("%d\n", strlen(p+1));//5
    printf("%d\n", strlen(*p));//err
    printf("%d\n", strlen(p[0]));//err
    printf("%d\n", strlen(&p));//随机
    printf("%d\n", strlen(&p+1));//随机
    printf("%d\n", strlen(&p[0]+1));//5*/

  /*  int a[3][4] = {0};

    printf("%d\n",sizeof (a));//48
    printf("%d\n",sizeof (a[0][0]));//4
    printf("%d\n",sizeof (a[0]));//16
    printf("%d\n",sizeof (a[0] + 1));//8 第一行第二个元素地址
    printf("%d\n",sizeof (*(a[0] + 1)));//4  第一行第二个元素地址解引用
    printf("%d\n",sizeof (a + 1));//8 此时的a为二位数组首元素地址，即第一行的地址，+1表示跳过第一行
    printf("%d\n",sizeof (*(a + 1)));//16
    printf("%d\n",sizeof (&a[0] + 1));//8
    printf("%d\n",sizeof ( *(&a[0] + 1) ));//16
    printf("%d\n",sizeof (*a));//16
    printf("%d\n",sizeof (a[3]));//16
    printf("%d\n",sizeof (&a));//8*/

/*    int a[5] = {1,2,3,4,5};

    int *ptr = (int*)(&a + 1);
    printf("%d,%d",*(a + 1),*(ptr - 1));//2,5*/

/*
    p = 0x100000;
    printf("%p\n",p+0x1);
    printf("%p\n",(unsigned long )p + 0x1);
    printf("%p\n",(unsigned int *)p + 0x1);
*/

    /*int a[4] = {1,2,3,4};
    int* ptr1 = (int*)(&a + 1);
    int* ptr2 = (int*)((int)a + 1);
    printf("%x,%x",ptr1[-1],*ptr2);*/


    /*int a[3][2] = {(0,1),(2,3),(4,5)};
    int *p;
    p = a[0];
    printf("%d",p[0]); //1*/

/*
    int a[5][5];
    int (*p)[4];
    p = a;

    printf("%p,%d",&p[4][2] - &a[4][2 ],&p[4][2] - &a[4][2]);//0xfffffffffffffffc,-4
*/


    /*int aa[2][5] = {1,2,3,4,5,6,7,8,9,10};
    int * ptr1 = (int*)(&aa+1);
    int * ptr2 = (int*)(*(aa+1));
    printf("%d,%d",*(ptr1 - 1),*(ptr2  - 1));//10,5*/


    /*char*a[] = {"work","at","alibaba"};
    char** pa = a;
    pa++;
    printf("%s\n",*pa);//at*/



    char* c[] = {"ENTER","NEW","POINT","FIRST"};
    char** cp[] = {c + 3,c + 2,c+1,c};
    char *** cpp = cp;
    printf("%s\n",**++cpp);//POINT
    printf("%s\n",*-- * ++cpp + 3);//ER
    printf("%s\n",*cpp[-2]+3);//ST
    printf("%s\n",cpp[-1][-1] + 1);//EW
    return 0;
}
