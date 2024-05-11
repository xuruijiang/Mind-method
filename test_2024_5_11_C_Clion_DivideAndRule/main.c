#include <stdio.h>
void quick_sort(int arr[],int l,int r){
    if(l>=r) return;
    int left=l,right=r;
    int p=arr[l];
    while(left<right){
        while(left<right && arr[right]>=p) --right;
        if(arr[right]<p) arr[left] = arr[right];

        while(left<right && arr[left]<=p) ++left;
        if(arr[left]>p) arr[right] = arr[left];

        if(arr[left]>=arr[right]) arr[left]=p;
    }
    quick_sort(arr,l,right-1);
    quick_sort(arr,right+1,r);
}


void main()
{
	int num,i;
    scanf("%d",&num);
    int a[num];
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);

    /**********  Begin  **********/
    quick_sort(a,0,num-1);
    printf("max1=%d max2=%d\n",a[num-1],a[num-2]);
    printf("min1=%d min2=%d",a[0],a[1]);
    /**********  End  **********/
}
