#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {


    char str[] = "abcdefgh";
    int n = 0;

    scanf(" %d ",&n);

    char temp;

    char str1[1000] = {0};

    for (int i = n; i < strlen(str); ++i) {

        str1[i - n] = str[i];
    }

    for (int i = 0; i < n; ++i) {

        str1[strlen(str) - n + i] = str[i];
    }


    printf("%s",str1);

    return 0;
}
