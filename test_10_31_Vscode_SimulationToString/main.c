#include <stdio.h>

int my_strlen(char *p){
    int count = 0;
    while (*p != '\0')
    {
        /* code */
        count++;
        p++;
    }

    return count;
    
}

int main(){

    char str[100] = "abcdfgg";
    printf("%d\n",my_strlen(str));

}