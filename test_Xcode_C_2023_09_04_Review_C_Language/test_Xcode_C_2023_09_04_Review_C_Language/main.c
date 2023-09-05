//
//  main.c
//  test_Xcode_C_2023_09_04_Review_C_Language
//
//  Created by 徐瑞江 on 2023/9/4.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
//    printf("hello world!!!\n");
//
//    printf("hehe!!!\n");
//
//    printf("char = %d\n",(int)sizeof(char));
//    printf("short = %d\n",(int)sizeof(short));
//    printf("int = %d\n",(int)sizeof(int));
//    printf("long = %d\n",(int)sizeof(long));
//    printf("long long = %d\n",(int)sizeof(long long));
//    printf("float = %d\n",(int)sizeof(float));
//    printf("double = %d\n",(int)sizeof(double));
    
    char ch = 'w';
    printf("%c\n",ch);
    
    float f = 75.5f;
    printf("%.2f\n",f);
    
//    double pai = 3.14;
//    int age = 24;
//    double wage = 20000.0;
    //创建变量的时候最好给个初始值,这是一个好习惯
    
    char a$s = 's';
    printf("%c\n",a$s); //$为什么可以，搞不明白
    
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d",&num1,&num2);
    
    int sum = num1 + num2;
    
    printf("num1 + num2 = %d\n", sum);
    
    
    return 0;
}
