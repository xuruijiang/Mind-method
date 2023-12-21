#include <stdio.h>
//    1. 黑洞数也称为陷阱数，又称“Kaprekar问题”，是一类具有
//    奇特转换特性的数。任何一个各位数字不全相同的三位数，
//    经有限次“重排求差”操作，总会得到495。最后所得的495
//    即为三位黑洞数。所谓“重排求差”操作即组成该数的数字重
//    排后的最大数减去重排后的最小数。例如，对三位数207：
//    第1次重排求差得：720 - 27 ＝ 693；第2次重排求差得：
//    963 - 369 ＝ 594；第3次重排求差得：954 - 459 ＝ 495；
//    编写程序,实现如下功能：输入一个三位整数，输出将其转换为
//    黑洞数的过程，输入输出格式为：
//    输入： 207
//    输出： 1：720-27=693
//    2：963-369=594
//    3：954-459=495
//    如果输入的三位数字全部相同，则只输出一次重排求差过程，
//    值为0就停止。

int main() {
    int one = 0, ten = 0, hundred = 0;
    int number = 0;
    int max = 0;
    int min = 0;
    int decent = 0;
    int count = 0;
    printf("输入:  \n");
    scanf("%d",&number);
    decent = number;
    do {
        count++;
        one = decent % 10;
        decent /= 10;
        ten = decent % 10;
        hundred = decent / 10;
        if(one >= ten && one >= hundred)
        {
            if(ten >= hundred)
            {
                max = one * 100 + ten * 10 + hundred;
                min = hundred * 100 + ten * 10 + one;
            }
            else
            {
                max = one * 100 + hundred * 10 + ten;
                min = ten * 100 + hundred * 10 + one;
            }

        }
        else if(ten >= one && ten >= hundred)
        {
            if(one >= hundred)
            {
                max = ten * 100 + one * 10 + hundred;
                min = hundred * 100 + one * 10 + ten;
            }
            else
            {
                max = ten * 100 + hundred * 10 + one;
                min = one * 100 + hundred * 10 + ten;
            }
        }
        else if(hundred >= one && hundred >= ten)
        {
            if(one >= ten)
            {
                max = hundred * 100 + one * 10 + ten;
                min = ten * 100 + one * 10 + hundred;
            }
            else
            {
                max = hundred * 100 + ten * 10 + one;
                min = one * 100 + ten * 10 + hundred;
            }
        }
        decent = max - min;
        printf("输出:  ");
        printf("       %d: %d-%d=%d\n",count,max,min,decent);
        if(decent == 0)
        {
            break;
        }
    } while (decent != 495);

    int aaa = 0;
    printf("%d",aaa);
    return 0;
}
