#include <stdio.h>



//, 据我理解原 来贪心算法就是，我每天都要
int maxProfit(int* prices, int pricesLen ) {
    // write code here

    if (pricesLen == 0 || pricesLen == 1){

        return 0;
    }
    int min = prices[0];
    int max_Profit = 0;

    for (int i = 0; i < pricesLen; ++i) {
        if (prices[i] < min){

            min = prices[i];
        } else{
            if (prices[i] - min > max_Profit){

                max_Profit = prices[i] - min;
            }

        }

    }


    if (max_Profit >= 0){
        return max_Profit;
    }

    return 0;

}

int main() {

    int a[10] = {0};


    for (int i = 0; i < 10; ++i) {
        scanf("%d",&a[i]);
    }

    printf("%d",maxProfit(a,10));

    return 0;
}
