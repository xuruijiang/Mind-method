#include <stdio.h>
#include <string.h>
#include <assert.h>


char* my_strstr(char* ptr1 ,char* ptr2){

    if(*ptr2 == '\0'){
        return ptr1;
    }
    assert(ptr1 && ptr2);
    char * p = ptr1;

    char * p2 = ptr2;
    if(strlen(ptr1) < strlen(ptr2)){
        return NULL;
    } else{


        while (*ptr1 != '\0'){
            ptr2 = p2;
            if(*ptr1 != *ptr2){
                ptr1++;
                if(strlen(p) - (ptr1 - p) < strlen(ptr2)){
                    return NULL;
                }
            } else{
                char *ptr = ptr1;
                ptr1++;
                ptr2++;
                char *ptr3 = ptr1;

                if(*ptr2 =='\0'){
                    return ptr;
                }

                while (ptr2 !='\0'){
                    if(*ptr1 == *ptr2){
                        ptr1++;
                        ptr2++;
                        if(*ptr2 == '\0'){
                            return ptr;
                        }
                    } else{
                        break;
                    }
                }

                ptr1 = ptr3;

            }
        }

    }

}
int main() {




    // char arr[] = {'a','b','c'};

    /*char arr[] = {'a','a','c',0,'a'};
    printf("%d\n", strlen(arr));//数字0直接断了，输出3，字符'0'就会输出5
    printf("%s\n",arr);*///aac,遇到\0停止，本质上\0与数字0相同。

    /*char arr[20] = {0};

    *arr = "hello";
    printf("%s\n",arr); 错误的写法*/


/*    char arr[20] = "dddddd";

    printf("%s\n",strcat(arr,"asd"));*/

    /*char *ptr = "xxxxxxxxx";
    char *p = "hello world";
    strcpy(ptr,p);
    printf("%s\n",*ptr);//直接崩盘*/


    /*char arr[20] = "abcdef";

    char a[30] = "aaaa";
    strcat(arr,a);
    printf("%s\n",arr);*/



    char arr1[] = "abbbbbbcdefabcdef";
    char arr2[] = "bbbbbcd";

    //printf("%s\n",arr1);

    char * ret = my_strstr(arr1,arr2);

    if(ret == NULL){
        printf("没找到\n");
    }else{
        printf("找到了:%s\n",ret);
    }

    return 0;
}

