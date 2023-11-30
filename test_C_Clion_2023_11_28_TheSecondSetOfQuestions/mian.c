//
// Created by 徐瑞江 on 2023/11/30.
//
#include <stdio.h>
#include <stdlib.h>
//4. 有一个名为 data。txt 的文本文件，请编写程
//序，实现如下功能：从文件中逐个读出字符，统计文
//件中所包含的各个英文字母（不分大小写）所出现的
//次数，英文字母之外的字符不用统计，用以下格式输
//出统计结果：a：12 b：1 c：10...z：90
//并将所有的非英文字符写入另外一个名为
//data_bak.txt 的文本文件中.
int main()
{
    int arr[26]={0};
    FILE *pf1 = fopen("/Users/xuruijiang/Downloads/data.txt","r");
    FILE *pf2 = fopen("/Users/xuruijiang/Downloads/data_bak.txt","a");
    //int i = 0;
    printf("%p\n",pf1);
    char c = (char)fgetc(pf1);
    while(c != EOF)
    {
        if(c >= 65 && c <= 90)
        {
            arr[c - 65]++;
        }
        else if(c >= 97 && c <= 122)
        {
            arr[c - 97]++;
        }
        else
        {
            fputc(c,pf2);
        }
        c = (char) fgetc(pf1);
    }

    for (int i = 0; i < 26; ++i) {

        printf("%c:%d ",i+97,arr[i]);
    }
    return 0;
}
