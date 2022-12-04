//#include <stdio.h>
//
//
//void my_strcpy(char *ptr1, char *ptr2){
//
//
//    while (*ptr2 != '\0'){
//        *ptr1++ = *ptr2++;
//    }
//
//
//
//}
//int main() {
//
//
//    char str1[] = "abcdefg";
//
//    char str2[20] ="0";
//
//    my_strcpy(str2,str1);
//
//    printf("%s\n",str2);
//    return 0;
//}

//
//  main.c
//  test_11_26_Xcode_PostgraduateTestPaperFour
//
//  Created by 徐瑞江 on 2022/11/26.
//

//4. 编写一个函数，函数功能为判断一个整数是否为质数。并写出主函数，调用该函数，将10000之内的所有质数输出到屏幕，每行输出10个数据，并统计一共有多少个质数；并将这些质数依次写入一个文件中，文件名为zhishu.dat，文件中的格式与输出格式一致。
//#include <stdio.h>
//#include <math.h>
//void primeNumber(int * arr , int * count){
//
//    int num = 0;
//    for (int i = 1; i <= 10000; ++i) {
//
//        num = 0;
//        for (int j = 2; j <= sqrt(i) && j < i; ++j) {
//
//            if(i % j == 0){
//
//                num = 1;
//                break;
//            }
//
//        }
//
//        if(num == 0){
//            printf("%d ",i);
//            arr[*count] = i;
//            (*count)++;
//
//            if(*count % 10 == 0){
//
//                printf("\n");
//            }
//
//        }
//    }
//
//
//}
//
//int main() {
//    // insert code here...
//
//    FILE * pf = fopen("/Users/xuruijiang/Desktop/zhishu.txt", "w");
//
//    int arr[10000] = {0};
//    int count = 0;
//    primeNumber(arr , &count);
//
//    for (int i = 0; i < count ; ++i) {
//        fputc(arr[i], pf);
//
//    }
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main( )
//{
//    int sum=0,item=0;
//    while (item<5)
//    {
//        item++;
//        sum+=item;
//        if(sum>=8)
//            break;
//    }
//    printf("%d\n",sum) ;
//    return 0;
//}

//#include <stdio.h>
//int main( )
//{
//    int i=0, a[]={3,4,5,4,3};
//    do{
//        a[i]++;
//    }while(a[++i]<5);
//    for(i=0;i<5;i++)
//        printf("%d ",a[i]);
//    return 0;
//}

//#include <stdio.h>
//int main( )
//{   int a[9]={1,2,3,4,5,4,3,2,1};
//    int *p,*q,i,x;
//    p=&a[0];  q=&a[8];
//    for (i=0;i<=4;i++)
//        if(*(p+i) == *(q-i) )
//            x=*(p+i)*2;
//    printf("%d\n",x);
//    return 0;
//}

//#include <stdio.h>
//int main( )
//{ int a[12]={1,2,3,4,5,6,7,8,9,10,11,12}, *p[4],i;
//    for(i=0;i<4;i++)
//        p[i]=&a[i*3];
//    printf("%d\n",p[3][2]);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main( )
//{
//    char s[20]="abcd",*p2="ABCD",str[50]="xyz";
//    strcpy(str+2, strcat(s+2,p2+1));
//    printf("%s\n", str);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main (  )
//{
//    int i;
//    char *s= "abcd";
//    for ( i=0 ; i<strlen(s); i++)
//        printf ("%s\n" ,s+i );
//    return 0;
//}

//#include <stdio.h>
//#define PT 5.5
//#define S(x) PT*x*x
//int main( )
//{    int a=1,b=2;
//    printf("%.1f\n" ,S(a+b));
//    return 0;
//}

//#include <stdio.h>
//int main( )
//{   int i;
//    for(i=0;i<3;i++)
//        switch(i)
//        {   case 1: printf("%d",i);
//            case 2: printf("%d",i);
//            default: printf("%d",i);
//        }
//    return 0;       }


//#include <stdio.h>
//int main( )
//{  int  x, y;
//    for(x=30, y=0; x>=10, y<10; x--, y++)
//        x/=2, y+=2;
//    printf("x=%d,y=%d\n",x,y);
//    return 0;
//}

//#include<stdio.h>
//int z=0;
//void f(int *x, int y)
//{
//    ++*x;
//    y--;
//    z=*x+y+z;
//    printf("%d %d %d\n",*x,y,z);
//}
//int main( )
//{
//    int x=1, y=5,z=9;
//    f(&x,y);
//    printf("%d %d %d\n",x,y,z);
//    return 0;
//}

//#include <stdio.h>
//void f(int *a,int n)
//{   int i,t;
//    for(i=0;i<n/2;i++)
//    {  t=a[i];a[i]=a[n-1-i];a[n-1-i]=t;}
//}
//int main( )
//{   int b[10]={1,2,3,4,5,6,7,8,9,10}; int i,s=0;
//    f(b+2,5);
//    for(i=5;i<10;i++)
//        s+=b[i];
//    printf("%d\n",s);
//    return 0;
//}

//#include <stdio.h>
//int f(int *a,int n)
//{   if(n>1)
//        return a[0] + f(&a[1],n-1);
//    else
//        return a[0];
//}
//int main( )
//{   int aa[ ]={1,2,3,4,5},s;
//    s=f(&aa[0],sizeof(aa)/sizeof(int));
//    printf("%d\n",s);
//    return 0;
//}

//#include <stdio.h>
//int fun(int k)
//{
//    static int a=0;
//    a+=k;
//    return a;
//}
//int main( )
//{  int i,s=0;
//    for (i=1; i<=4; i++)
//        s=s+fun(i);
//    printf("s=%d\n",s);
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main( )
//{
////    char ch[3][5]={"135","246","789"},*p[3];
////    int i,j,s=0;
////    for(i=0;i<3;i++) p[i]=ch[i];
////    for(i=0;i<3;i++)
////        for(j=0;p[i][j]>='0'&&p[i][j]<='9';j+=2)
////            s=10*s+p[i][j]-'0';
////    printf("%d\n",s);
//
//    int a = 7;
//    double x = 2.5, y = 4.7;
//
//    printf ("%1f\n", x + (a % 3) * ((int)(x + y) %2) /4);
//
//    printf("%d",35);
//    return 0;
//}

#include <stdio.h>
void inverse(){
    char str[100] = {0};


    if(scanf("%s",str) != EOF){
        inverse();
        printf("%s ",str);
    }

}

int main(){

    inverse();
    return 0;
}

// 撤销动作。dd