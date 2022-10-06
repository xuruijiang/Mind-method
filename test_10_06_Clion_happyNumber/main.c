#include <stdio.h>
#include <stdbool.h>


bool isHappy(int n){

    if(n == 1){
        return true;
    }

    int nums = 0;
    int number = 0;

    while (1){
        n = nums;

        while(1){
            nums = nums + ((n%10)*(n%10));

            if(n/10 == 0){
                break;
            }
            n = n/10;
        }

        if(nums == 1){
            return true;
            break;

        }


        number++;
        if(number > 10000){
            return false;
        }
    }




}
int main() {

    int num = 19;
     if(isHappy(num) == false){
         printf("false\n");

     } else{
         printf("true\n");
     }
    return 0;
}
