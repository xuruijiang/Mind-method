#include <stdio.h>
#include <string.h>
#include <assert.h>


char* solve(char* str ) {
    // write code here

    assert(str);
    int right = 0;
    char mid;
    if( (right = (int)strlen(str)) == 0){
        return "";
    } else{
        int left = 0;
        while (left < right - 1 ){

            mid = str[left];
            str[left] = str[right - 1];
            str[right - 1] = mid;
            left++;
            right--;
        }
    }

    return str;
}
int main() {


    char str[] = "abcdef";

//    char* p = str;
//
//    char m ;
//    m = p[0];
//
//    p[0] = p[4];
//    p[4] = m;
//  printf("%c", p[0]);
// printf("%c", p[4]);
//    printf("%c", p[2]);




    printf("%s",solve(str));
    return 0;
}
