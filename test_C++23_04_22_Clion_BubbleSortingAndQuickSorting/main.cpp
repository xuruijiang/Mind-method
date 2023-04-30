#include <iostream>
#include <unistd.h>

void process_bar()
 {

int i = 0;

int j = 0;

char arr[21] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};


    for(i = 0; i < strlen(arr); i++)
     {

         printf("[");
         arr[i] = '#';

         for(j = 0; j < strlen(arr) + 1; j++)
         {
             if(j == 20)
             {
                 printf("\\%");
                 printf("%d",(i * 5) );
                 continue;
             }
             if(arr[j] != 1)
             {
                 printf("%c",arr[j]);
             }
             else
             {

                 printf(" ");
             }

         }//for
             printf("]");
         fflush(stdout);
             sleep(1);
             printf("\r");
     }//for结束
}
int main() {
//    long l = 0;
//    printf("%d",sizeof(l));
//    printf("你好 你就是垃圾 !\r");
//    fflush(stdout);
//    sleep(2);
//    printf("nihao\r");
//    fflush(stdout);
//    sleep(3);
//    printf("你好 你就是垃圾 !\n");
    process_bar();

    return 0;
}
