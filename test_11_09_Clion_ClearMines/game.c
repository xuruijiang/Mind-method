//
// Created by 徐瑞江 on 2022/11/9.
//

#include "game.h"
void arrayAssign(char arr[ROWS][COLS]){

    for (int i = 1; i < ROWS - 1; ++i) {

        for (int j = 1; j < COLS - 1; ++j) {

            arr[i][j] = '*';
        }
    }

}

void show(char arr[ROWS][COLS]){
    for (int i = 0; i < ROWS - 1; ++i) {
        printf("%d ",i);
    }
    printf("\n");

    for (int i = 1; i < ROWS - 1; ++i) {
        for (int j = 0; j < COLS - 1; ++j) {
            if(j == 0){
                printf("%d ",i);
            } else{
                printf("%c ",arr[i][j]);
            }

        }
        printf("\n");
    }


}

void buriedMine(char arr[ROWS][COLS]){

    int row , col;
    int count = 0;

    while (count < ((ROW +ROWS)/2)){
        row = rand() % ROW + 1;
        col = rand() % COL + 1;
        if (arr[row][col] == 0){
            arr[row][col] = '1';
            count++;
        }
    }
    show(arr);

}

int IsBurid(char arr[ROWS][COLS],int row , int col){
    int count = 0;

    for (int i = row - 1; i <= row +1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            if (arr[i][j] == '1'){
                count++;
            }

        }
    }

    return count;
}

void markThunder(char arr[ROWS][COLS],int row,int col){

    if (arr[row][col] == '*'){
        arr[row][col] = '@';
    } else if (arr[row][col] == '@'){
        arr[row][col] = '*';
    } else{
        printf("输入行列号不符合规则!!!");
    }

}

int isWin(char arr[ROWS][COLS]){

    int count = 0;
    for (int i = 1; i < ROWS - 1; ++i) {

        for (int j = 1; j < COLS - 1; ++j) {

            if (arr[i][j] == '*' || arr[i][j] == '@'){
                count++;
            }

        }
    }

    if (count == ((ROWS + ROW)/2)){
        return 1;
    }

    return 0;
}