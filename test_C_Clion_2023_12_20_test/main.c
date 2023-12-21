//#include <stdio.h>
//
//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}
#include<stdio.h>
#include<string.h>
char* f(char* str)
{
    char* start = str;
    while (*str)
    {
        if ((*str >= 'a') && (*str <= 'x'))

        {
            *str += 2;
        }
        if((*str >= 'A') && (*str <= 'X'))
        {
            *str += 2;
        }

        if ((*str >= 'y' && *str <= 'z') || (*str >= 'Y' && *str <= 'Z'))
        {
            *str -= 24;
        }
        if (*str >= '0' && *str <= '8')
        {
            *str += 1;
        }
        if (*str == '9')
        {
            *str = '0';
        }
        str++;
    }
    return start;
}
int main()
{
//    char s[100];
//    FILE* pf = fopen("data.txt", "w");
//
//    for (int i = 0; i < 1; i++)
//    {
//        scanf("%s", s);
//        printf( "%s\n", f(s));
//    }
//    fclose(pf);
//    pf = NULL;

    char c = 'w';
    f(&c);
    printf("%c",c);

    return 0;
}
//有问题的代码，帮佬邦看的