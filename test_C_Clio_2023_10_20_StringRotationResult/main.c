#include <stdio.h>
#include <string.h>
#define SIZE 20
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 =AABCD和s2 = BCDAA，返回1
//给定s1=abcd和s2=ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

//--------------------------------------------------//
int Revolve_left(char arr1[SIZE], char arr2[SIZE], int temp, int len)
{
    char arr3[SIZE] = {0};
    if(strlen(arr2) != strlen(arr1))
    {
        return 0;
    }//if
    else
    {
//        if(temp == 0)
//        {
//            if(strcmp(arr1,arr2) == 0)
//            {
//                return 1;
//            }//if
//            else
//            {
//                return 0;
//            }//else
//        }//if

        for (int i = 0; i < temp; ++i) {
            //arr3[len - temp + i] = arr1[i];
            arr3[len - 1 - i] = arr1[i];
        }//for

        for (int i = 0; i < len - temp; ++i) {
            arr3[i] = arr1[temp + i];
        }//for
    }//else
    if(strcmp(arr2,arr3) == 0)
    {
        return 1;
    }//if
    else
    {
        return 0;
    }//else
}
//--------------------------------------------------//
int Revolve_right(char arr1[SIZE], char arr2[SIZE], int temp, int len)
{
    char arr3[SIZE] = {0};
    if(strlen(arr2) != strlen(arr1))
    {
        return 0;
    }//if
    else
    {
//        if(temp == 0)
//        {
//            if(strcmp(arr1,arr2) == 0)
//            {
//                return 1;
//            }//if
//            else
//            {
//                return 0;
//            }//else
//        }//if

        for (int i = 0; i < temp; ++i) {
            //arr3[i] = arr1[len - temp + i];
            arr3[i] = arr1[len - 1 - i];
        }//for

        for (int i = 0; i < len - temp; ++i) {
            arr3[temp + i] = arr1[i];
        }//for
    }//else
    if(strcmp(arr2,arr3) == 0)
    {
        return 1;
    }//if
    else
    {
        return 0;
    }//else

}
//--------------------------------------------------//
int main() {

    char arr1[SIZE] = "ABCDEFGHIJK";
    //char arr2[SIZE] = "KJIABCDEFGH";
    char arr2[SIZE] = {0};
    scanf("%s",arr2);

    int choose = 0;
    for (int i = 0; i < strlen(arr1) - 1; ++i) {
        if(Revolve_left(arr1,arr2,i, strlen(arr1)) == 1)
        {
            choose = 1;
            printf("yes_left\n");
        }//if
    }//for

    for (int i = 0; i < strlen(arr1) - 1; ++i) {
        if(Revolve_right(arr1,arr2,i, strlen(arr1)) == 1)
        {
            choose = 1;
            printf("yes_right\n");
        }//if
    }//for

    if(choose == 0)
    {
        printf("no\n");
    }
    return 0;
}
