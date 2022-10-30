#include <stdio.h>

struct stu{

};


int main(){

    struct stu s;

    printf("%ld\n",sizeof(struct stu));
    printf("%ld\n",sizeof(s));
    printf("hello\n");


    int count = 0;
    while (scanf("%d",&count) != EOF)
    {
        /* code */

        if (count > 0)
        {
            /* code */
            printf("1\n");
        }else if(count == 0){
            printf("0.5\n");

        }else{

            printf("0\n");

        }
        
    }
    

    return 0;

}