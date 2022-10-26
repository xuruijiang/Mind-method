#include <stdio.h>
#include <stdlib.h>
int main() {


    char arr[10] = "*********";

    FILE * pf = fopen("/Users/xuruijiang/Desktop/data.txt","r");

    if (pf == NULL){

        perror("fopen");
        return 1;
    }

     arr[0] = fgetc(pf);

    printf("%c\n",arr[0]);



    fclose(pf);
    pf = NULL;
    return 0;
}
