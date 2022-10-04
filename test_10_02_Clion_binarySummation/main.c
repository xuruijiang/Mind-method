//
//  main.c
//  test_10_02_Xcode_binarySummation
//
//  Created by 徐瑞江 on 2022/10/2.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str;

char * addBinary(char * a, char * b){


    if(a[0] == '0'){
        return b;
    }else if(b[0] == '0'){
        return a;
    }

    int lenthOne = (int)strlen(a);
    int lenthTwo = (int)strlen(b);
    int count = 0;
    int lenth = (lenthOne>lenthTwo)? lenthOne:lenthTwo;
    int shortlen = (lenthOne<lenthTwo)? lenthOne:lenthTwo;
    str = (char*)malloc(lenth+2);

    for (int i = 0; i < lenth; ++i) {


        if(i < shortlen){
            str[lenth - 1 - i] = (char)(a[lenthOne - 1 - i] + b[lenthTwo - 1 - i] - 48);
        }else if(lenthOne == lenth){
            str[lenth - 1 - i] = a[lenthOne - 1 - i];
        }else if(lenthTwo == lenth){
            str[lenth - 1 - i] = b[lenthTwo - 1 - i];
        }




    }



    for (int i = 0; i < lenth; ++i) {
        if(str[lenth - 1 - i] + count == '0' || str[lenth - 1 - i] + count == '1'){
            str[lenth - 1 - i] = str[lenth - 1 - i] + count;
            count = 0;
        } else if(str[lenth - 1 - i] + count == '2' || str[lenth - 1 - i] + count== '3'){
            str[lenth - 1 - i] =   (char)(str[lenth - 1 - i] + count - 2);
            count = 1;

        }
    }

    if(count == 1){

        for (int i = 0; i < lenth; ++i) {
            str[lenth - i] = str[lenth - 1 - i];
        }

        str[0] = '1';
    }


    return str;


}
int main() {


    char a[] = "0";
    char b[] = "11111111";//1001100


    addBinary(a,b);
    printf("%s\n",str);

    free(str);
    str = NULL;
    return 0;
}
