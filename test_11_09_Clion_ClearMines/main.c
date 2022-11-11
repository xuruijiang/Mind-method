#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include "game.c"

void menu(){

    printf("*******************************\n");
    printf("*************1.play************\n");
    printf("*************0.exit************\n");
    printf("*******************************\n");
}


void game(){

    char tableMain[ROWS][COLS] = {0};
    char tableShow[ROWS][COLS];

    //数组赋值
    arrayAssign(tableShow);
    //埋雷
    buriedMine(tableMain);
    //显示扫雷游戏
    show(tableShow);
    int row,col;
    int choose = 1;


    do {
        printf("请输入需要做的事1.标记雷 2.点开格子: >");
        int n = 0;
        scanf("%d",&n);
        switch (n) {
            case 1:
                printf("请输入标记(取消)雷的行列号: >");
                int rowOne,colOne;
                scanf("%d %d",&rowOne,&colOne);
                if (rowOne >= 1 && rowOne <= ROW && colOne >=1 && colOne <= COL){
                    markThunder(tableShow,rowOne,colOne);
                    show(tableShow);
                } else{
                    printf("输入不和规则，请重新输入");
                }
                if (isWin(tableShow) ==1 ){
                    printf("恭喜您，获胜!!!");
                    choose = 0;
                }
                break;
            case 2:

                printf("请输入点开的格子: >");
                scanf("%d %d",&row,&col);

                if (row >= 1 && row <= ROW && col >=1 && col <= COL){

                    //判断格子雷情况
                    if (tableMain[row][col] == '1'){
                        printf("游戏失败,踩到雷了\n");
                        choose = 0;
                        break;

                    }else{


                        tableShow[row][col] = IsBurid(tableMain,row,col) + 48;

                        if(tableShow[row][col] == '0'){
                            //判断周围雷情况
                            for (int i = row - 1; i <= row +1; ++i) {
                                for (int j = col - 1; j <= col + 1; ++j) {
                                    tableShow[i][j] = IsBurid(tableMain,i,j) + 48;

                                }
                            }
                        }
                        show(tableShow);
                        if (isWin(tableShow) == 1 ){
                            printf("恭喜您，获胜!!!");
                            choose = 0;
                        }
                    }


                }else{
                    printf("输入不符合规则，请重新输入\n");
                }
                break;
            default:
                printf("输入不合规则，请重新输入\n");
                break;
        }


    } while (choose);

}

/*void test(int *arr){

    for (int i = 0; i < 15; ++i) {

        printf("%d,",*(arr+i));
    }




}*/

/*void test(char *arr){

    printf("%d\n",sizeof(arr));//8
    printf("%d\n",strlen(arr));//8
}*/
int main() {

    /*int arr[10] = {1,2,3,4,5};

    printf("%d\n",(sizeof(arr)/sizeof(arr[0]) ));*/
    /*   char str[] = "ssssssss";

       test(str);

       printf("%d\n",sizeof(str));//9 //sizeof 对于字符串，会将\0也计算进去。*/

    /*  int arr[3][5] = {1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};

      test(arr);

      printf("%p\n",arr);
      printf("%p\n",&arr[0][0]);*/
    /*
     * 改不了
     * const int  a = 10;

     int* p = &a;
     *p = 20;

     printf("a =  %d\n",a);*/


    /*  int ii ;

      int arrrr[10] = {1,2,3,4,5,6,7,8,9,10};
      for (ii = 0; ii <= 10 ; ++ii) {

          arrrr[ii] = 0;
          printf("%d hehe\n",ii);
      }

      scanf("%d",&ii);*/

    srand((unsigned int)time(NULL));

    int input = 0;
    do {

        menu();
        printf("请选择: >");

        scanf("%d",&input);

        switch (input) {
            case 1:
                printf("游戏开始\n");
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

