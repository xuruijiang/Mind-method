//
//  main.c
//  test_9_28_theSquareVal
//
//  Created by 徐瑞江 on 2022/9/28.
//

#include <stdio.h>

int Sqrt(int x ) {
    // write code here
    static double count = 0;

    if(x == 1){

        return x;
    } else if(x == 0){
        return 0;
    }

    if(count == (double)0){

        count = (double )x/ 1.0f;
        Sqrt(x);
    } else{
        if((count -  (count + ((double)x / count))/2.0f) > 0.001f){
            count = (count + ((double)x / count))/2.0f;

            Sqrt(x);
        }

    }

    return (int)count;

}
int main() {

    int val = 0;

    printf("请输入一个数字！！！");
    scanf("%d",&val);

    int a =  Sqrt(val);
    printf("%d\n",a);
    return 0;
}
