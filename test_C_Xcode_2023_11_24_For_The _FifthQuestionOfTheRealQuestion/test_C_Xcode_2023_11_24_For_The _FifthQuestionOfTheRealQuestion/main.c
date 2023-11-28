//
//  main.c
//  test_C_Xcode_2023_11_24_For_The _FifthQuestionOfTheRealQuestion
//
//  Created by 徐瑞江 on 2023/11/24.
//

#include <stdio.h>
#include <string.h>
//5.编写函数f,f的功能是对一个字符串进行简单加密,加密规则为:英文字母用该字母之后的第二个 字母 替换 ,即 字母 a用 字母 c替 换 ,字 母 b用 字母 d替 换 , ̈ ⋯,字 母 y用 字母 a替 换 ,字 母 z用 字母 b 替换 ;数 字字符进行加 1处 理 ,即 字符 0用 字符 1替 换 ,字 符 1用 字符 2替 换 。⋯ ̈字符 9用 字符 0替 换 , 其他字符保持不变。并编写主函数,实现如下功能:输入 10个字符串,调用函数f对字符串进行加密, 并将加密之后的 10个字符串写入文件 data.txt中 。

//#define ADD((x),(y)) x + y 错的

#define S(x) 1*x*x

void f(char *s, int size)
{
    for (int i = 0; i < size; ++i) {
        if(s[i] >= 48 && s[i] <= 56 )
        {
            s[i] += 1;
        }
        if(s[i] == 57)
        {
            s[i] = 48;
        }
        
        if((s[i] >= 63 && s[i] <= 86) || (s[i] >= 97 && s[i] <= 120))
        {
            s[i] += 2;
        }
        
        if(s[i] == 87 || s[i] == 88 )
        {
            s[i]-=9;
        }
        
        if(s[i] == 121 || s[i] == 122)
        {
            s[i]-=24;
        }
        
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    //double a = 3E4;
    long ll = 3323L;
    printf("%d\n",S(5+3));
    
    //printf("%d",sizeof(long));
    
    char s[1000];
    FILE* pf = fopen("/Users/xuruijiang/Desktop/data.txt", "a");
    
    for (int i = 0; i < 10; ++i) {
        scanf("%s",s);
        f(s,(int)strlen(s));
        fputs(s,pf);
        fputs("\n", pf);
    }
    return 0;
}
