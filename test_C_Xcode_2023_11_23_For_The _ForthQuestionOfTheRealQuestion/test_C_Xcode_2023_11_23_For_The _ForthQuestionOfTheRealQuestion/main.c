//
//  main.c
//  test_C_Xcode_2023_11_23_For_The _ForthQuestionOfTheRealQuestion
//
//  Created by 徐瑞江 on 2023/11/24.
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//4.输入100个整数，对这100个整数进行排序，排序方法
//为：按照整数中数字6出现的次数进行升序排列，次数相
//同时，则按照实际大小进行升序排列，输出排序之后的数
//据。如待排序的5个整数值为：16， 266，666，9，166，
//则排序之后的数据为：9，16，166，266，666。

void sort(int *data, int num)
{
    int tmp = 0;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num - i - 1; ++j) {
            if(data[j] > data[j + 1])
            {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int data1[100];
    int data2[100];
    int data3[100] = {0};
    int data4[100] = {0};

    for (int i = 0; i < 100; ++i) {
        //scanf("%d",&data1[i]);
        data1[i] = rand();
    }//for
    int num = 1;
    for (int i = 0; i < 100; ++i) {
        num = data1[i];
        if(num == 0)
        {
            data2[i] = 0;
        }//if
        while(num != 0)
        {
            if(num%10 == 6)
            {
                data2[i]++;
            }//if
            num = num/10;
        }//while
    }//for

    for (int i = 0; i < 100; ++i) {
        printf("%d, ",data1[i]);
    }
    printf("\n");
    for (int i = 0; i < 100; ++i) {
        printf("%d, ",data2[i]);
    }
    //计算6的个数
    for (int i = 0; i < 100; ++i) {
           data3[data2[i]]++;
    }

    printf("\n");
    for (int i = 0; i < 100; ++i) {
        printf("%d ",data3[i]);
    }
    int count = 0;
    int h = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {

            if(data2[j] == h)
            {
                data4[count++] = data1[j];
            }

            if(count == 100)
            {
                break;
            }
        }//内for

        if(count == 100)
        {
            break;
        }
        h++;
    }//外for
    printf("\n");
    for (int i = 0; i < 100; ++i) {
        printf("%d ",data4[i]);
    }
    count = 0;
    h = 0;
    while (count != 100) {
        sort(data4 + count, data3[h]);
        count += data3[h];
        h++;
    }
    
    printf("\n");
    
    for (int i = 0 ; i < 100; ++i) {
        printf("%d  ",data4[i]);
    }

    return 0;
}









