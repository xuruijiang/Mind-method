#include <stdio.h>
#include <string.h>
//2．编写程序，实现功能：输入一个字符串（长度不超过80），
//对字符串进行如下处理：如果字符是大写字符，则用该字符对
//应的小写字符替换，如果字符是小写字符，则用该字符对应的
//大写字符替换，其他字符则保持不变，输出经过处理的字符串。
//如输入：abKY12，则输出为：ABky12。（说明：本题不允许使
//用string.h中的函数strlwr、strupr）
int main() {

    char str[100] = {0};
    scanf("%s",str);
    for (int i = 0; i < strlen(str); ++i) {
        if(str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
        else if(str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
    }
    printf("%s\n",str);
    return 0;
}
