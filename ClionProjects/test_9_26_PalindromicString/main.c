#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


bool judge(char* str ) {
    // write code here
    assert(str);
    int left = 0;
    int right = 0;
    char mid;
    if((right = strlen(str)) == 0){

        return false;
    } else if(right == 1){
        return true;
    }else{

        while (left < right){

            if(str[left] == str[right - 1]){
                ;
            } else{
                return false;
            }

        }

    }

    return true;
}


int main() {

    char str[] = "abcba";

    bool a = judge(str);

    return 0;
}
