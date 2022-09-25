#include <stdio.h>


    void find_num(int arr[5][5],int x,int y,int k) {
        int choose = 1;
        int n = 0;

        do {
            if (arr[n][y - 1] == k) {
                break;
            } else if(arr[n][y-1] > k){
                y--;
                if(y<0){
                    choose = 0;
                }
            } else if(arr[n][y-1] < k){
                n++;
                if(n>x-1) {
                    choose = 0;
                }
            }

        } while (choose);

        if(choose == 1){
            printf("找到了,arr[%d][%d]",n,y-1);
        }else{
            printf("没找到");
        }

    }

int main() {

    int k = 24;

    int arr[5][5] = {1,2,3,4,5,
                     6,7,8,9,10,
                     11,12,13,14,15,
                     16,17,18,19,20,
                     21,22,23,24,25};
    find_num(arr,5,5,k);

    return 0;
}
