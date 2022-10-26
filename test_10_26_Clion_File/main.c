#include <stdio.h>
#include <stdlib.h>
int main() {


    char arr[10] = "*********";

    FILE * pf = fopen("/Users/xuruijiang/Desktop/data.txt","r");

    if (pf == NULL){

        perror("fopen");
        return 1;
    }
    fgets(arr,8,pf);
    fgets(arr,8,pf);



    printf(arr);

    fclose(pf);
    pf = NULL;
    return 0;
}
