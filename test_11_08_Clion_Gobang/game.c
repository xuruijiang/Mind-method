//
// Created by 徐瑞江 on 2022/11/8.
//


#include "game.h"
//判断输赢
int IsWin(char board[ROW][COL]){
    int choose = 2;
    if ((board[0][0] == '*' && board[0][1] == '*' && board[0][2] == '*')
        || (board[0][0] == '*' && board[1][0] == '*' && board[2][0] == '*')
        || (board[0][0] == '*' && board[1][1] == '*' && board[2][2] == '*')
        || (board[0][1] == '*' && board[1][1] == '*' && board[2][1] == '*')
        || (board[0][2] == '*' && board[1][2] == '*' && board[2][2] == '*')
        || (board[0][2] == '*' && board[1][1] == '*' && board[2][0] == '*')
        || (board[1][0] == '*' && board[1][1] == '*' && board[1][2] == '*')
        || (board[2][0] == '*' && board[2][1] == '*' && board[2][2] == '*')){
        return 1;
    }

    if ((board[0][0] == '#' && board[0][1] == '#' && board[0][2] == '#')
        || (board[0][0] == '#' && board[1][0] == '#' && board[2][0] == '#')
        || (board[0][0] == '#' && board[1][1] == '#' && board[2][2] == '#')
        || (board[0][1] == '#' && board[1][1] == '#' && board[2][1] == '#')
        || (board[0][2] == '#' && board[1][2] == '#' && board[2][2] == '#')
        || (board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#')
        || (board[1][0] == '#' && board[1][1] == '#' && board[1][2] == '#')
        || (board[2][0] == '#' && board[2][1] == '#' && board[2][2] == '#')){
        return 1;
    }

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (board[i][j] == ' '){
                return 0;
            }
        }
    }

    return choose;

}

void PlayerMove(char board[ROW][COL]){

    printf("玩家走\n");
    int row,col;

    while (1){
        printf("请输入您要下的位置: >");
        scanf("%d %d",&row,&col);

        if(row > 0 && row < (ROW + 1) && col > 0 && col < (COL + 1) && board[row - 1][col - 1] == ' '){
            board[row - 1][col - 1] = '*';
            break;

        }

        printf("输入位置不对，请重新输入\n");

    }



}

void ComputerMove(char board[ROW][COL]){
    printf("电脑走\n");
    int row,col;

    while (1){

        row = rand() % ROW;
        col = rand() % COL;

        if (board[row][col] == ' '){
            board[row][col] = '#';
            break;
        }
    }

}

void InitBoard(char board[ROW][COL]){

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            board[i][j] = ' ';
        }
    }

}

void DisplayBoard(char board[ROW][COL]){

    for (int i = 0; i < ROW; ++i) {

        for (int j = 0; j < COL; ++j) {
            printf(" %c ",board[i][j]);
            if(1 != COL - j){
                printf("|");
            }

        }
        printf("\n");

        if(1 != ROW - i){
            for (int h = 0; h < COL; ++h) {

                printf("---");
                if(1 != COL - h){
                    printf("|");
                }

            }
            printf("\n");
        }


    }

}