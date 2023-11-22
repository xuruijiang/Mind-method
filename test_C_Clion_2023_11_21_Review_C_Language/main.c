#include<stdio.h>
#include <string.h>

//int main(){
//        char ss[10]= "12345";
//
//        gets(ss);
//
//        strcat(ss,"6789");
//
//        printf("%s",ss);
//
//        return 0;
//}

int main()
{
//    int x = 0;
//    int y = 1;
//    int z = 0;
//
//    if(x=z=y)
//        x=3;
//    printf("%d,%d\n",x,z);
//
//    int a[][3] = {1,2};
//    printf("%d",sizeof)

//    int a = 011,b=0x11,c=11;
//    printf("%o,%x,%d",a,b,c);

    int a[3][2] = {1,2,3,4,5,6};
    int aa[3] = {1,2,3};
    printf("%d\n",*(aa + 1));
    printf("%d\n",*(a[1] + 1));
    return 0;

}