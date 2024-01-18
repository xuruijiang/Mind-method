//#include <iostream>
//using namespace std;
//namespace bit{
//    int a = 0;
//
//    namespace N1{
//        int a = 1;
//    }
//
//
//}
//
//void fun(int a , int b = 20, int c = 30)
//{
//
//}
//
//int main() {
//    //cout << "Hello, World!" <<endl;
//    cout << bit::N1::a << endl;
//    return 0;
//}

#include<iostream>
using namespace std;
#include<string.h>
char* reverses(const char* s, char* d)
{
    /*1.四个二进制数组成一个十六进制数
        2.查表*/
    int count = 0;
    int temp = 0;
    /*int len = strlen(d);
    char* ret = new char[len];
    ret = d;*/
    char* ret = d;
    char look[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    while (*s)
    {
        switch (*s)
        {
            case '0':
            {
                count++;
                break;
            }

            case '1':
            {
                count++;
                temp +=(1<<(4-count));
                break;
            }
            default:
                break;
        }
        if (4 == count)
        {
            *d = look[temp];
            d++;
            count = 0;
            temp = 0;

        }
        s++;
    }
    return ret;
}
int main()
{
    char arr[] = "1100 1000 1101";
    /*int len = sizeof(arr)/ sizeof(arr[0]);
    char* arr1 = new char[len];*/
    char arr1[20] = {0};
    reverses(arr,arr1);
    printf("%s", arr1);
    return 0;
}