//
//  main.c
//  test_9_29_Xcode_validParentheses
//
//  Created by 徐瑞江 on 2022/9/29.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


bool isValid(char * s){

    int lenth = (int)strlen(s);
    char *p = (char*)malloc(lenth+ 2);
    int flag = 0;
    memset(p,0, lenth);

    for (int i = 0; i < lenth; ++i) {

        if(*(s + i) == '(' || *(s + i) == '[' || *(s + i) == '{' ){
            flag++;
            *(p + flag) = *(s + i);

        }else if ( (int)*(s + i) == (int)*(p + flag) + 1 || (int)*(s + i) == (int)*(p + flag) + 2 ){
            flag--;
        }else{

            return false;
        }
    }

    if(flag){
        return false;
    }

    return true;
}
int main() {


    char str[10000];
    scanf("%s",str);

    if(isValid(str) == false){
        printf("false\n");
    } else{
        printf("true\n");
    }
    return 0;
}
//([([)]])
