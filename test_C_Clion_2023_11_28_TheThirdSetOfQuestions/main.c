#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//5.请编写函数将十进制数转换成八进制数。函数名为f，
//函数参数及返回值自己定义，编写主函数， 实现如下
//功能：输入100个十进制整数，调用函数f，将它们转
//换为八进制数，并输出，假设输入的前3 个数据为：
//15， 80， 90，则前三行对应的输出为：
//15>>>17
//80>>>120
//90>>>132
void f(int arr[100],int number)
{

    int tmp = 0;
    for (int i = 0; i < number; ++i) {

        for (int j = 0; arr[i] > 0; ++j) {
            tmp += arr[i]%8 * (int)pow(10,j);
            arr[i] = arr[i]/8;
        }
        arr[i] = tmp;
        tmp = 0;
    }

    for (int i = 0; i < number; ++i) {
        printf("%3d ",arr[i]);
    }

}
int main() {
    srand((unsigned)time(NULL));
    int arr[100] = {0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        arr[i] = rand()%100;
    }
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%3d ",arr[i]);
    }
    printf("\n");

    f(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
