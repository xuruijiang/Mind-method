#include <stdio.h>
#include <string.h>

void str_inverse( char *str, int num){
    int left = 0;
    int right = num;

    while (left < right){

        str[left] = str[right] ^ str[left];
        str[right] = str[right] ^ str[left];
        str[left] = str[right] ^ str[left];
        left++;
        right--;
    }

}

int main() {

    char str[] = "abcdefgh";

    str_inverse(str,strlen(str) - 1);


    printf("%s\n",str);
    return 0;
}
