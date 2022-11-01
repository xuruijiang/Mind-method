#include <stdio.h>

int my_strlen(char *p){

    if(*p == '\0'){
        return 0;
    }else{
        return 1 + my_strlen(p + 1);
    }
}
int main(){
    char str[100] = "edddsjdjskaaa";
    //scanf("%s",str);
    printf("%d\n",my_strlen(str));

}