#include <stdio.h>
#include<string.h>

void fun(){

    printf("sss\n");
}
int main(){
    fun();
    int num = 0;
    scanf("%d",&num);
    int oddNumber[16] = {0};
    int evenNumber[16] = {0};
    int numCopy = num;

    for (int i = 0; i < 15; i++)
    {
        if((numCopy & 1) == 1 ){
            oddNumber[i] = 1;
        }else{
            oddNumber[i] = 0;
        } 

        numCopy = numCopy >> 2;
    }
    
    numCopy = num >> 1;
    for (int i = 0; i < 15; i++)
    {
        
        if((numCopy & 1) == 1 ){
            evenNumber[i] = 1;
        }else{
            evenNumber[i] = 0;
        } 

        numCopy = numCopy >> 2;
    }

    for (int i = 15; i >= 0; i--)
    {
        /* code */
        printf("%d",oddNumber[i]);
    }
    printf("\n");
    for (int i = 15; i >= 0; i--)
    {
        /* code */
        printf("%d",evenNumber[i]);
    }

    return 0;
}