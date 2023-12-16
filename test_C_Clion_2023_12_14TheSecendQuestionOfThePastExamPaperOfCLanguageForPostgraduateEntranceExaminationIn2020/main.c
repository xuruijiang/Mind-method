#include <stdio.h>
//2. 编写一个函数，实现字符串的复制，函数首部定义为
//：char * str_copy(char *d, char *s)
//函数功能为：将第二个参数s所表示的字符串复制到第一个
//参数d所表示的字符串中，函数返回值为第一个参数的值。
//请写出完整的函数，并写出主函数，对该函数进行验证。
//（说明：本题不允许使用string.h中的标准函数，不允许改变函数首部）

char* str_copy(char *d, char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        d[i] = s[i];
        i++;
    }

    return d;
}
int main() {
    char s[20] = "asc329r3udsdf";
    char d[20] = {0};
    char * p = str_copy(d,s);
    printf("%s\n",p);
    return 0;
}
