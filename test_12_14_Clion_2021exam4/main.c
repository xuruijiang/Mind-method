#include <stdio.h>

void fun_array(int * p,int * min,int * max,int n){


    for (int i = 1; i < n; ++i) {
        if( *(p + i) > *max){

            *max = *(p + i);
        } else if(*(p + i) < *max){

            *min = *(p + i);
        }

    }


}

#define bue(a) (a)-(a)
int main() {


    printf("%d\n", bue(2+3) * 5);

    int data[20],i;
    for (i = 0; i < 20; i++) {

        scanf("%d",data+i);


    }

    int min = data[0];
    int max = data[0];
    fun_array(data,&min,&max,sizeof(data)/sizeof(data[0]));

    printf("max = %d, min = %d",max,min);

    return 0;
}
