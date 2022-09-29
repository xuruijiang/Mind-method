#include <stdio.h>
#include <string.h>


char * longestCommonPrefix(char ** strs, int strsSize){

    if (strsSize < 2 ){
        return strs[0];
    }

    int j = 0;
    int i = 0;
    int flag = 0;

    printf("%c\n",*(strs[0] + 3));//这里打印都没问题
    for ( i = 0; ; ++i) {
        for ( j = 1; j < strsSize; ++j) {
            if(*(strs[j] + i) == '\0' || *(strs[j] + i) != *(strs[j - 1] + i)){
                flag = 1;
                *(strs[0] + i) = '\0'; //说我这里有问题
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }

    return strs[0];
}
int main() {

    char *str[5] = {"abcteyd","abcccvv","abceggg","abclfkf","abcldud"};

    //char (*p)[20] = &str[0];

    longestCommonPrefix(str,5);
    return 0;
}

