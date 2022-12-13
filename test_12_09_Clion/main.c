//#include <stdio.h>
//
///*
//编写一个函数，实现对一个整数加密处理，加密方法为：
//如果整数为负数，则加密之后结果为该数的绝对值；如果
//整数为非负数，加密方式将个位上的数字加6，如果超过10，
//则取个位上的数字。如-12，加密之后结果为12；356加密
//之后结果为352。函数名为fun_pass，参数及返回值请根据
//函数功能设计。编写主函数，实现如下功能：输入100个整
//数，调用函数fun_pass对这些数据进行加密处理，并将加
//密之后的数据，写入文件data.txt中。
//*/
//
//int * fun_pass(int * arr){
//
//    int n = 0;
//
//    int sum = 0;
//
//    for (int i = 0; i < 10; ++i) {
//
//        if(*(arr + i) < 0){
//            *(arr + i) = 0 - *(arr + i) ;
//        } else{
//            n = *(arr + i)%10;
//            sum = n + 6;
//            if(sum > 9){
//                *(arr + i) = *(arr + i) - n + sum % 10;
//            } else{
//                *(arr + i) = *(arr + i) + 6;
//            }
//        }
//    }
//
//    return arr;
//
//}
//int main() {
//
//
////    int number = 0;
////    char c = 0;
////
////
////    scanf("%d",&number);
////    c = getchar();
////    scanf("%c",&c);
////
////    printf("%d,%c\n",number,c);
//
//    /*char arrr[6] = "abcdef";
//    printf("%s",arrr);
//*/
//    // printf("%d",sizeof (float ));
//
////    char a = 127;
////    a = a<<1;
////    printf("%d\n",a);
//
//    int arr[10] = {0};
//
//    for (int i = 0; i < 10; ++i) {
//        scanf("%d",&arr[i]);
//    }
//
//    int *p =  fun_pass(arr);
//
//    for (int i = 0; i < 10; ++i) {
//        printf("%d,",*(p + i));
//    }
//
//    FILE * fp = fopen("/Users/xuruijiang/考研相关/2021年硕士研究生入学考试试题/data.txt","w");
//
//    if(fp == NULL){
//        perror("fopen");
//        return 1;
//    }
//    for (int i = 0; i < 10; ++i) {
//        fprintf(fp,"%d\t",*(p + i));
//    }
//
//    fclose(fp);
//    fp = NULL;
//    return 0;
//
//
//}

//
//  main.c
//  test_12_12_Xcode_Exam
//
//  Created by 徐瑞江 on 2022/12/12.
//


//4。 有一个名为 data。txt 的文本文件，请编写程序，实现如下功能：从文件中逐个读出字符，统计文件中所包含的各个英文字母（不分大小写） 所出现的次数，英文字母之外的字符不用统计，用以下格式输出统计结果：
//
//a：12 b：1 c：10。。。。z：90
//
//并将所有的非英文字符写入另外一个名为 data_bak.txt 的文本文件中。

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...


    int arr[26] = {0};
    int c = 0;
    FILE * pfOne = fopen("/Users/xuruijiang/考研相关/2022年考研真题/data.txt", "r");
    FILE * pfTwo = fopen("/Users/xuruijiang/考研相关/2022年考研真题/data_bak.txt", "w");

    if(pfOne == NULL){
        perror("fopen");
        return 1;
    }
    if(pfTwo == NULL){

        perror("fopen");
        return 1;
    }

//    c = fgetc(pfOne);
//    printf("%c",c);

    while ((c = fgetc(pfOne)) != EOF) {

        if( c >= 65 && c <= 90){

            arr[c - 65]++;


        }else if ( c >= 97 && c <= 122){
            arr[c - 97]++;

        }else{

            fputc(c, pfTwo);
        }

    }


    for (int i = 0; i < 26; ++i) {

        printf("%c : %d  ",i + 97,arr[i]);

    }

    fclose(pfOne);
    fclose(pfTwo);
    pfOne = NULL;
    pfTwo = NULL;


    return 0;
}
