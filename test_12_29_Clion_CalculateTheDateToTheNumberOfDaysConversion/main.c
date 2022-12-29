#include <stdio.h>
#include <string.h>


//描述
//        根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
//进阶：时间复杂度：O(n)\O(n) ，空间复杂度：O(1)\O(1)
//输入描述：
//输入一行，每行空格分割，分别是年，月，日
//
//        输出描述：
//输出是这一年的第几天

int isLeapYear(int num){

    if((num % 4 == 0 && num % 100 != 0) || num % 400 == 0){
        return 1;

    } else{
        return 0;
    }
}

int main() {

//    char s[] = "\\123456\123456\t";
//    printf("%d\n",strlen(s));
//
//    char a[14] = "hello world!";
//    char aa[14];
//    aa = "hello world!";

    int year = 0;
    int moon = 0;
    int day = 0;

    int data = 0;

    scanf("%d%d%d",&year,&moon,&day);

    switch (moon) {

        case 1:
            data += day;
            break;
        case 2:
            data = 31 + day;
            break;
        case 3:
            data = 31 + 28 + day;
            break;
        case 4:
            data = 31 + 28 + 31 + day;
            break;
        case 5:
            data = 31 + 28 + 31 + 30 + day;
            break;
        case 6:
            data = 31 + 28 + 31 + 30 + 31 + day;
            break;
        case 7:
            data = 31 + 28 + 31 + 30 + 31 + 30 + day;
            break;
        case 8:
            data = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
            break;
        case 9:
            data = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
            break;
        case 10:
            data = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
            break;
        case 11:
            data = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
            break;
        case 12:
            data = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
            break;
        default:
            printf("请输入合法月份\n");
    }


    if(isLeapYear(year) == 1 && moon > 2){

        data++;
    }

    printf("%d",data);

    return 0;
}
