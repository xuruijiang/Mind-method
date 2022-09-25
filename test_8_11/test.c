#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <time.h>
#include "game.c"
#include "game.h"
void game(){
    //存储数据-二维数组
    char board[ROW][COL];
    //初始化棋盘-初始化空格
    InitBoard(board);
    //打印棋盘
    DisplayBoard(board);


    while (1){
        //玩家下棋
        PlayerMove(board);
        //打印棋盘
        DisplayBoard(board);
        //判断玩家是否赢得游戏
        if (IsWin(board) == 1){
            printf("恭喜您，赢得游戏！！！\n");
            break;
        }

        if (IsWin(board) == 2){
            printf("平局！！！\n");
            break;
        }


        //电脑下棋
        ComputerMove(board);
        //打印棋盘
        DisplayBoard(board);
        //判断电脑是否赢得游戏
        if (IsWin(board) == 1){
            printf("别灰心，再接再厉！！！\n");
            break;
        }
        if (IsWin(board) == 2){
            printf("平局！！！\n");
            break;
        }


    }



}

void menu(){
    printf("**********************************\n");
    printf("***********   1.play   ***********\n");
    printf("***********   0.exit   ***********\n");
    printf("**********************************\n");

}

int main(){

    int input;
    srand((unsigned)time(NULL));
    do {

        menu();

        printf("请选择: >");
        scanf("%d",&input);

        switch (input) {
            case 1:
                printf("开始三子棋游戏\n");
                game();
                break;
            case 0:
                printf("游戏结束\n");
                break;
            default:
                printf("输入不合规则，请重新输入\n");
                break;
        }

    } while (input);

    return 0;
}
