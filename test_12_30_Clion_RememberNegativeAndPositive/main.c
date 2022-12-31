#include <stdio.h>
//首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
//0即不是正整数，也不是负数，不计入计算。如果没有正数，则平均值为0。
//
//数据范围： 1 \le n\ \le 2000 \1≤n ≤2000  ，输入的整数都满足 |val| \le 1000 \∣val∣≤1000
int main() {

    int n = 0;
    scanf("%d",&n);
    int num = 0;
    int m = 0;
    int h = 0;
    double average = 0.0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&num);

        if(num < 0){
            m++;
        }else if( num > 0){
            average+=num;
        } else{
            h++;

        }

    }

    if( n - m - h  == 0){
        printf("%d %.1lf",0,0.0);
    } else{
        average = average/(n - m - h);
        printf("%d %.1lf",m,average);
    }

    return 0;
}
