#include <stdio.h>
#include <stdio.h>

/*
编写一个函数，实现对一个整数加密处理，加密方法为：
如果整数为负数，则加密之后结果为该数的绝对值；如果
整数为非负数，加密方式将个位上的数字加6，如果超过10，
则取个位上的数字。如-12，加密之后结果为12；356加密
之后结果为352。函数名为fun_pass，参数及返回值请根据
函数功能设计。编写主函数，实现如下功能：输入100个整
数，调用函数fun_pass对这些数据进行加密处理，并将加
密之后的数据，写入文件data.txt中。
*/

int * fun_pass(int * arr){

    int n = 0;

    int sum = 0;

    for (int i = 0; i < 10; ++i) {

        if(*(arr + i) < 0){
            *(arr + i) = 0 - *(arr + i) ;
        } else{
            n = *(arr + i)%10;
            sum = n + 6;
            if(sum > 9){
                *(arr + i) = *(arr + i) - n + sum % 10;
            } else{
                *(arr + i) = *(arr + i) + 6;
            }
        }
    }

    return arr;

}
int main() {

    /*char arrr[6] = "abcdef";
    printf("%s",arrr);
*/
   // printf("%d",sizeof (float ));

    int arr[10] = {0};

    for (int i = 0; i < 10; ++i) {
        scanf("%d",&arr[i]);
    }

    int *p =  fun_pass(arr);

    for (int i = 0; i < 10; ++i) {
        printf("%d,",*(p + i));
    }

    FILE * fp = fopen("/Users/xuruijiang/考研相关/2021年硕士研究生入学考试试题/data.txt","w");

    if(fp == NULL){
        perror("fopen");
        return 1;
    }
    
    for (int i = 0; i < 10; ++i) {
        fprintf(fp,"%d\t",*(p + i));
    }

    fclose(fp);
    fp = NULL;
    return 0;


}
