#include <stdio.h>

int main() {

    int n = 0;
    n = 10;
    while(n)
    {
        printf("%d, ",n);
        n--;
    }//while

    printf("\n");


    char ch,cg;
    ch = getchar();
    cg = getchar();

    printf("%c\n",ch);
    printf("%c\n",cg);
    return 0;
}
