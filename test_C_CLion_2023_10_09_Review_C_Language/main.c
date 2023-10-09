#include <stdio.h>
#define ROW 3
#define COL 3

//-------------------------------------------------//
void menu(){
    printf("********************************\n");
    printf("***********   1. play   ********\n");
    printf("***********   0. exit   ********\n");
    printf("********************************\n");
}
//-------------------------------------------------//
void init_board(char board[ROW][COL], int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            board[i][j] = ' ';
        }//内for
    }//外for
}
//-------------------------------------------------//
void printf_board(char board[ROW][COL], int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(" %c ",board[i][j]);
            if(j != col - 1)
            {
                printf("|");
            }//if
        }//内for
        printf("\n");
        if(i != row - 1)
        {
            for (int j = 0; j < col; ++j) {
                printf("--- ");
            }
            printf("\n");
        }//if
    }//外for

}
//-------------------------------------------------//
int isWin(char board[ROW][COL],int row, int col){
    for (int i = 0; i < row; ++i) {
        if(board[i][1] == board[i][2] && board[i][2] == board[i][0] && board[i][0] != ' ')
        {
            return 1;
        }//if
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        {
            return 1;
        }//if
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' '
        || board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
        {
            return 1;
        }//if
    }//for

    return 0;

}
//-------------------------------------------------//
void game(){
    char board[ROW][COL];
    init_board(board,ROW,COL);
    printf_board(board,ROW,COL);

    int input = 1;
    int row = 0;
    int col = 0;
    do {
        printf("请输入行和列\n");
        scanf("%d%d",&row,&col);
        if(!(row <= ROW && row > 0 && col <= COL && col > 0 && board[row - 1][col - 1] == ' '))
        {
            printf("输入不合法\n");
            continue;
        }//if
        if(input % 2 == 1)
        {
            board[row - 1][col - 1] = 'o';
            printf_board(board,ROW,COL);
        }//if
        else
        {
            board[row - 1][col - 1] = 'x';
            printf_board(board,ROW,COL);
        }//else
        input++;
    }while(!isWin(board,ROW,COL));
    if(input % 2 == 0)
    {
        printf("玩家1获胜\n");
    }//if
    else
    {
        printf("玩家2获胜\n");
    }//else
}
//-------------------------------------------------//
void test(){
    int input = 0;

    do {
        menu();
        printf("请选择\n");
        scanf("%d",&input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("游戏退出\n");
                break;
            default:
                printf("斐法输入，重新输入\n");
                break;
        }//switch
    }while(input);


}
//-------------------------------------------------//

int main() {
    test();
    return 0;
}
