//
// Created by 徐瑞江 on 2022/8/11.
//
#include <stdio.h>
#ifndef TEST_8_11_GAM_H
#define TEST_8_11_GAM_H

#endif //TEST_8_11_GAM_H
#pragma once
//符号的定义
#define ROW 3
#define COL 3


//函数的声明

//初始化棋盘
void InitBoard(char board[ROW][COL]);

//打印棋盘
void DisplayBoard(char board[ROW][COL]);

//玩家下棋
void PlayerMove(char board[ROW][COL]);

//电脑下棋
void ComputerMove(char board[ROW][COL]);

//判断输赢
int IsWin(char board[ROW][COL]);