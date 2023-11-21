#include<stdio.h>
#include <string.h>

int main(){
        char ss[10]= "12345";

        gets(ss);

        strcat(ss,"6789");

        printf("%s",ss);

        return 0;
}