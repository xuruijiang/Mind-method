#include <stdio.h>
#include <string.h>
//-----------------------------------------------//
int greatestCommonDivisor(int num1, int num2)
{
    int large = (num1 > num2)? num1 : num2;
    int small = (num1 < num2)? num1 : num2;
    int k = 0;
    while((k = (large % small)))
    {
        large = small;
        small = k;
    }
    return small;
}
//-----------------------------------------------//

//-----------------------------------------------//
int main() {

//    char ch[20] = "hajdhajhd\0saa";
//    printf("%s\n",ch);
    char ch[20] = "hello bit";
    memset(ch,'a',5);
    printf("%lu\n",sizeof ch);
    printf("%s\n",ch);

    for (int i = 0; i < sizeof ch; ++i) {
        printf("%d, ",ch[i]);
    }
    printf("\n");
    char ch1[20] = {0};
    strcpy(ch1,ch);
    for (int i = 0; i < sizeof ch; ++i) {
        printf("%d, ",ch1[i]);
    }
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d",&num1,&num2);
    int CommonDivisor = greatestCommonDivisor(num1,num2);
    printf("%d\n",CommonDivisor);
    return 0;
}
//-----------------------------------------------//

//最小公倍数等于两个数想乘再除以最大公约数