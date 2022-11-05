
#include <stdio.h>

int right = 0;

void  reverse_string(char * string){

    string[right] = string[right] ^ *string;
    *string = *string ^ string[right];
    string[right] = *string ^ string[right];

    if(&string[right - 1] - (string + 1) > 0){
        right -= 2;
        reverse_string(string + 1);
    }

}

int main() {

    char str[] = "abcdefghims";
    char *p = str;
    while( *p != '\0' ){

        right++;
        p++;
    }
    right--;

    reverse_string(str);
    printf("%s\n",str);
    return 0;
}
