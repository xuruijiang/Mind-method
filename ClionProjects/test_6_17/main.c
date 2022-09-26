#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#include "test.c"


int Add(int x, int y){

    int z = x+y;

    return z;
}

#define MAX 1000

//#define ADD(x,y) x+y

#define ADD(x,y) ((x)+(y))
typedef int u_int;

struct Book{
    char name[20];
    int price;
    char BookId[20];
};

int Compare(int a,int b){
    if (a>b){
        return a;
    } else{

        return b;
    }

}

int Multiplication(int n){

    int sun = 1;
    for (int i = 1; i <=n; ++i) {
       sun = sun * i;
    }
    return sun;


}

game(){

    int true = 0;

        true =  (rand())%100 + 1;
        //true = true%100;
        int guess = 0;

    do {
        printf("请输入你的猜想数字：");
        scanf("%d",&guess);

        if (guess == true){
            printf("恭喜您，猜对了\n");
            break;
        } else{

            printf("猜错了，请继续\n");
            if (guess > true){
                printf("您的数字偏大\n");
            }else{
                printf("您的数字偏小\n");

            }

        }
    } while (guess != true );



}

void test(int n){
    if (n<1){
        test(n+1);
    }
    printf("%d\n",n);

}

int Fib(int n){

    if (n <= 2 ){
        return 1;
    } else{

        return Fib(n - 1) + Fib(n - 2);
    }

}


int main() {
    printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(long ));
    printf("%d\n",sizeof(long long));
    printf("%d\n",sizeof(double ));
    printf("%d\n",sizeof(float ));

    printf("%d\n",sizeof (int*));
    printf("%d\n",sizeof (short *));
    printf("%d\n",sizeof (char *));
    printf("%d\n",sizeof (long *));
    printf("%d\n",sizeof (double *));
    printf("%d\n",sizeof (float *));
    printf("%d\n",sizeof (long long *));

//    int asss = 10;
//    int arru[asss];

    int arru[10] = {0};

    printf("%d\n",sizeof(arru));


    //数组名是首元素的地址

    int  aaaaass = 0;
    int number = sizeof(aaaaass);
    printf("%d\n",number);
    char arrrss[] = "bit"; //四个元素，最后一个\0

    printf("%d\n", strlen(arrrss));
    char arrss1[] = {'b','i','t'};//三个字符
    printf("%s\n",arrss1);
    printf("怎么会 %d\n", strlen(arrss1)); //随机值
    //printf("%c\n",arrrss[3]);
//    int  sds = strlen(arrrss);
//    printf("%d\n",sds);


    char ass[] = "abcde2f'\022'2221212";


    int vf = strlen(ass);
    printf("%d\n",vf);

    char chr[5] = {'b','i','t'};

     int vv =  strlen(chr);
    printf("%d\n",vv);

    int nnnnn = 40;

    //nnnnn = 5,6,7;
    //nnnnn = nnnnn + 2 = 3; err

    printf("%d\n",nnnnn);

//    int ret = Fib(nnnnn);
//    printf("%d\n",ret);
//
//
//    test(1);
//    int a,b ;

   // printf("%d\n",(a=3)&&(b=-3));

  /*  int a[ ]={0,1,2,3,4,5,6,7,8,9},*p=a, i=3;

    int m = a[p-a];
    //int m = p[i];
    //int m = *(&a[i]);
    printf("%d\n",m);*/
    //a[p+a];
    /*  int a[12]={1,2,3,4,5,6,7,8,9,10,11,12}, *p[4],i;
      for(i=0;i<4;i++)
          p[i]=&a[i*3];
      printf("%d\n",p[3][2]);*/


    char nam[20] = "hello bit";

    memset(nam,'w',5);

    printf("%s\n",nam);

    /*gonn:

    goto gonn;*/

    int aaaaaaaaaaa = 16;

    int  asd = sqrt(aaaaaaaaaaa);//sqrt() 开平方函数

    printf("%d\n",asd);

    switch (3) {

        default: aaaaaaaaaaa = 5;
        case 1:
            aaaaaaaaaaa = 3;
            break;
    }

    printf("%d\n",aaaaaaaaaaa);


    int choose = 0;

    srand(time(NULL));
    do {
        printf("*****************************\n");
        printf("***********1.play************\n");
        printf("***********0.exit************\n");
        printf("*****************************\n");
        printf("请输入数字选择游戏与否:");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                printf("游戏开始\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;

            default:
                printf("输入数字不和规则，请重新输入:");
                break;
        }
    } while (choose != 0);




    //strcmp(s,s);   用来比较两个字符串是否相同；返回值为0；则相同； 比的是对应字符的acii码值，当出现第一个不同时则比较完成，前面比后面小则返回<0，。。。。。。大返>0;

    char arr1[] = "welcome to bit !!!!";
    char arr2[] = "###################";
    int left = 0;
    int right = strlen(arr1) - 1;


    while (left <= right){
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];

        printf("%s\n",arr2);
        sleep(1);

        left++;
        right--;

        //system("cls");

    }


    printf("计算1！..+..+10！\n");

    int nnn = 10;
    int summmm = 0;
    for (int i = 1; i <= 10; ++i) {
        summmm += Multiplication(i);
    }

    printf("1到10的阶乘和为:%d\n",summmm);

    int nur = 0;
    printf("请输入几的阶乘：");
    scanf("%d",&nur);

    int summ =  Multiplication(nur);

    printf("%d的阶乘是：%d\n",nur,summ);


    char arr[20] = { 0 };
    printf("请输入密码:");
    scanf("%s",arr);
    getchar();
    printf("请确认密码Y/N\n");
    int ch = getchar();
    if(ch == 'Y'){
        printf("确认成功\n");

    } else{

        printf("确认失败！\n");
    }


    int acc,bcc;
  /*  acc= 18;
    if(18<=acc<30){
        printf("错了");
    }*/

    printf("请输入两个整数中间用空格或者回车隔开：\n");
    scanf("%d%d",&acc,&bcc);

    int big =  Compare(acc,bcc);

    printf("较大整数为: %d\n",big);



    /*int test = 10;
    char arr8[test] = {0}; 错误 */

    int test = 10;
    char arr8[test];





    char arr6[] = {'a','b','c'};
    printf("%d\n", strlen(arr6));


    struct Book book = {"斗破苍穹",39,"666666"};

    struct Book *ps = &book;


    printf("《斗破苍穹》价格为：%d\n", book.price);
    printf("斗破苍穹这本书的地址为：%d\n",(*ps).price);
    printf("书名: %s  价格: %d  书单号: %s  \n", ps->name,ps->price,ps->BookId);


    printf("%d\n",sizeof (int*));
    printf("%d\n",sizeof (short *));
    printf("%d\n",sizeof (char *));
    printf("%d\n",sizeof (long *));
    printf("%d\n",sizeof (double *));
    printf("%d\n",sizeof (float *));
    printf("%d\n",sizeof (long long *));
//    int test = 12;
//
//    int* pa = &test;
//
//    int * paa = &pa;
//
//    printf(&pa,"\n",&paa);


    printf("%d\n", 4*ADD(2,3));
    printf("%d \n",MAX);

    Test();
    u_int annn = 8;
    int  aaaa= 2;
    printf("%d   %d\n",annn,aaaa);


    int  x,y,z;
    scanf("%d%d%d",&x,&y,&z );
    printf("%d" ,x+y+z);



    //int x = 1;


    x = (int)12.5 % 4 ;
    x = (++x)+(++x)+(++x);
    printf("x == %d\n",x);

    int num1;
    int num2;
    printf("请输入num1和num2的值\n");
    scanf("%d%d",&num1,&num2);

    int sum1 = Add(num1,num2);

    printf("sum =%d \n", sum1);

    int line = 0;
    while (line<3){
        line++;
        printf("写代码 %d \n",line);
    }
    if(line==3){
        printf("好offer\n");
    }



    int input = 0;
    printf("你要好好学习吗？0/1\n");
    scanf("%d", &input);
    if(input == 1){
        printf("好offer\n");
    } else{
        printf("种红薯\n");
    }
//    printf("\a\a\a");
//    #define MAX = 100
//
//    int arr[MAX] = {0};

    enum Sex{MALE,FEMALE,SECRET};
    int len = strlen("abc");

    printf("len = %d\n", len);
    const int h = 100;
    printf(" h = %d\n", h);
    printf("Hello, World!\n");
    printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(long ));
    printf("%d\n",sizeof(long long));
    printf("%d\n",sizeof(double ));
    printf("%d\n",sizeof(float ));

    double weight = 70.3;

    weight = weight - 10;

    printf("%lf\n",weight  );

    printf("\n");
    int au = 0;
    int bb = 0;
    int sum = 0;

    scanf("%d %d" ,&au,&bb );

    sum = au + bb;
    printf("%d\n",sum);




    return 0;
}

