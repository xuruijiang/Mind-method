#include <stdio.h>
#include <string.h>


int lengthOfLastWord(char * s){

    int lenth = strlen(s);

    int k = 0;
    int count = 0;
    for (int i = 0; i < lenth; ++i) {
        if(s[i] == ' '){
            k = 0;
        } else{
            k++;
            count = k;
        }

    }

    if(k == 0){
        return count;
    } else{
        return k;
    }

}
int main() {


    char str[] = "Hello World ";

    int k = lengthOfLastWord(str);


    printf("%d\n",k);
    return 0;
}
