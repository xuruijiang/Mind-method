#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Game(){
    int true = 0;
    true =  (rand())%100 + 1;

    int guess = 0;

    do {
        printf("请输入你的猜想数字：");
        scanf("%d",&guess);

        if (guess == true){
            printf("恭喜您，猜对了\n");
            break;
        } else{

            printf("猜错了，请继续\n");
            if (guess > true){
                printf("您的数字偏大\n");
            }else{
                printf("您的数字偏小\n");

            }

        }
    } while (guess != true );


}
int main() {


    int count = 0;

    srand(time(NULL));

    while (1){
        printf("*******************************************\n");
        printf("***************  1. paly  *****************\n");
        printf("***************  2. exit  *****************\n");
        printf("*******************************************\n");
        printf("请选择：");
        scanf("%d",&count);
        switch (count) {
            case 0:
                printf("游戏退出\n");
                exit(0);
                break;
            case 1:
                Game();
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    }


    return 0;
}
