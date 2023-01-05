#include <stdio.h>

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//
//
//
//以下为4个嫌疑犯的供词:
//
//
//
//A说：不是我。
//
//B说：是C。
//
//C说：是D。
//
//D说：C在胡说
//
//        已知3个人说了真话，1个人说的是假话。
//
//
//
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
int main() {

    int A,B,C,D;

    for (A = 0; A <= 1; ++A) {
        for (B = 0; B <= 1; ++B) {
            for (C = 0; C <= 1; ++C) {
                for (D = 0; D <= 1; ++D) {
                    if((A == 0) + (C == 1) + (D == 1) + (D == 0) == 3 && A + B + C + D == 1){
                        goto label;
                    }
                }
            }
        }
    }

    label:
    if(A == 1){
        printf("凶手是A");
    } else if( B == 1){
        printf("凶手是B");
    } else if( C == 1){
        printf("凶手是C");
    } else{
        printf("凶手是D");
    }
    return 0;
}
