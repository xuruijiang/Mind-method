//
//  main.c
//  test_23_03_11_Xcode_HelpFoeXinYu
//
//  Created by 徐瑞江 on 2023/3/11.
//



#include<stdio.h>
#include<string.h>
#include<assert.h>
//[表情]rncpy模拟实现
char* my_strncpy(char* dest, char* src,size_t num )
{
    assert(dest && src);
    char* ret = dest;
    while ( num > 0  && (*dest++ = *src++) )
    {
        num--;
    }
    if (num != 0)
    {
        while (num-- && (dest - ret) < 20)
        {
            *dest = 0;
            dest++;
        }
    }
    return ret;
}
int main()
{

//    double i ;
//    int m;
//    float n;
//    long k;
//    m = n = k = i = 20/3;
//    printf("%.1f\n",i);
    char arr1[] = "abcdsadadad";
    char arr2[20];
    my_strncpy(arr2, arr1, 20);
    printf("%s\n", arr2);

    return 0;
}
