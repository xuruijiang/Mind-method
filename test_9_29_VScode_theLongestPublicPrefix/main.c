#include <stdio.h>
#include <string.h>


char * longestCommonPrefix(char ** strs, int strsSize){

    if (strsSize < 2 ){

        return strs[0];
    }
    {
        /* code */
    }
    
    int j = 0;

    printf("%c\n",*(strs[0] + 3));

    int i = 0;
    int flag = 0;
    for ( i = 0; ; ++i) {
        for ( j = 1; j < strsSize; ++j) {
            if(*(strs[j] + i) == '\0' || *(strs[j] + i) != *(strs[j - 1] + i)){
                flag = 1;
                *(strs[0] + i) = '\0';
                break;
            }

        }

        if(flag == 1){
            break;
        }
    }

    // if(flag == 1){
    //     *(strs[0] + i) = '\0';
    // }

    return strs[0];

}
int main() {


    char *str[5] = {"abcteyd","abcccvv","abceggg","abclfkf","abcldud"};

    //char (*p)[20] = &str[0];

    longestCommonPrefix(str,5);
    return 0;
}

