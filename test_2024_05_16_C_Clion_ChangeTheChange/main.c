#include <stdio.h>

void main()
{
    /**********  Begin  **********/
    int j,GZ,A,B[7]={100,50,20,10,5,2,1},S[7]={0,0,0,0,0,0,0};
        scanf("%d",&GZ);
        for(j=0;j<=6;j++)
        {
            A=GZ/B[j];
            S[j] = A;
            GZ = GZ - A*B[j];
            printf("%d元 %d张\n",B[j],A);
        }
    /**********  End  **********/
}
