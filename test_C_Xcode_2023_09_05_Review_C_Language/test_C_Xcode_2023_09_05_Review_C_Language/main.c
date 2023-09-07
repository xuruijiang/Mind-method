//
//  main.c
//  test_C_Xcode_2023_09_05_Review_C_Language
//
//  Created by 徐瑞江 on 2023/9/5.
//

#include <stdio.h>

/*
 常量：
 字面常量
 const修饰的常量
 #define定义的常量
 枚举常量
 */
#define M 100

enum aa{
    A = 9,
    B,
    C
};
extern int f;
int main(int argc, const char * argv[]) {
    // insert code here...
    {
            
        printf("枚举：%d\n",A);
        int a = 10;
    
        a = 10;
    }//大括号会框出一个作用域，代码块
    
    
    //printf("%d\n",a); 不能用了，因为除了作用域
        
    printf("%d\n",f);
    
    
    const int constant = 100;
    //int arr[constant] = {0};
    printf("未修改的常变量%d\n",constant);
    int * p = (int *)&constant;
    *p = 10;
    printf("*p = %d\n",*p);
    int** p1 = &p;
    **p1 = 1;
    printf("&constant = %p\n",&constant);
    printf("p = %p\n",p);
    printf("*p = %d\n",*p);
    printf("通过指针修改常变量%d\n",constant);
    //指针修改const修饰的常变量其实也是不对的，不同编译器都不一样的
    char ch[] = {'a', 'b', 'c'};
    //char m = 'f';
    char ch1[] = "abc";
    //ch1[3] = 'd';
    printf("ch =  %s\n",ch);//这里按理就是乱码的
    printf("ch1 = %s\n",ch1);
    printf("ch = %p\n",ch);
    printf("ch1 = %p\n",ch1);
    printf("ch大小 %d\n",(int)sizeof(ch));
    printf("ch1大小 %d\n",(int)sizeof(ch1));
    
    //\b退格符
    
//    if(1 > 0)
//    {
//        printf("if通过\n");
//
//    }//if结束
    
    int line = 0;
    
    while (line <= 20000) {
        
        printf("敲代码\n");
        line++;
    }
    
    if(line > 20000)
    {
        printf("年薪两万\n");
    }//if结束
    else
    {
        printf("好好学习，天天向上\n");
    }//else结束
    
    
    printf("");
    return 0;
}

int f = 111;
