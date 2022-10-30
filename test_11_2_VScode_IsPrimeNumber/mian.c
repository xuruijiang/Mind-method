#include <stdio.h>
#include <math.h>

void is_prime_number(){

    int count = 0;

    for (int i = 101; i <= 200; i += 2)
    {
        count = 0;
        /* code */
        for (int j = 2; j <= sqrt(i); j++)
        {
            /* code */
            if(i % j == 0){
                count = 1;
                break;
            }else{
                continue;
            }

        }

        if(count == 0){
            printf("%d ",i);
        }
        

    }
    
}

int main(){

    is_prime_number();
    
    return 0;
}