#include <stdio.h>

int main(){

    int count = 0;
    while (scanf("%d",&count) != EOF)
    {
        /* code */

        if (count > 0)
        {
            /* code */
            printf("1\n");
        }else if(count == 0){
            printf("0.5\n");

        }else{

            printf("0\n");

        }
        
    }
    

    return 0;

}