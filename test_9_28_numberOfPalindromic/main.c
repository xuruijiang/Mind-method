#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(int x){

    char str[25] = {0};
    int i = 0;
    
   
    
    //itoa(x,str,10);
    if( x < 10 && x >= 0){
        return true;
    } else if(x < 0){
        return false;
    }

    
    while (1) {
        str[i] = (char)(x%10 + 48);
        
        if((x = x/10) == 0){
            break;
        }
        
        i++;
       
    }
    int lenth = (int)strlen(str);

    int left = 0;
    int right = lenth - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;

}
int main() {

    int a = 1000000001;


    if(isPalindrome(a) == false){
        printf("false\n");
    } else{
        printf("true\n");
    }
    return 0;
}
