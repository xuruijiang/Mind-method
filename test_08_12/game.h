//
// Created by 徐瑞江 on 2022/8/11.
//
#include <stdio.h>
#ifndef TEST_08_12_GAME_H
#define TEST_08_12_GAME_H

#endif //TEST_08_12_GAME_H

#define ROW 9
#define COL 9

#define ROWS (ROW + 2)
#define COLS (COL + 2)

void arrayAssign(char arr[ROWS][COLS]);
void show(char arr[ROWS][COLS]);
void buriedMine(char arr[ROWS][COLS]);
int IsBurid(char arr[ROWS][COLS],int row,int col);
void markThunder(char arr[ROWS][COLS],int row,int col);
int isWin(char arr[ROWS][COLS]);