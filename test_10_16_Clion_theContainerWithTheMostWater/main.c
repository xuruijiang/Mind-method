#include <stdio.h>
#include <string.h>

enum Color{
    BLUE = 2,
    RED,
    GREEN

};

int maxArea(int* height, int heightSize){


    int maxArea = 0;
    int hgit = 0;

    for (int i = 0; i < heightSize - 1; ++i) {

        //hgit = 0;

        for (int j = i + 1; j < heightSize; ++j) {
            hgit = (height[i] > height[j])? height[j] : height[i];

            if(hgit * (j - i) > maxArea){

                maxArea = hgit * (j - i);
            }



        }

    }

    return maxArea;

}

int main() {

    //char arr1[] = {'2','b','3'};
    //printf("%d\n",strlen(arr1));
    //printf("\a");


    int a = 3;

    scanf("%d",&a);
    printf("a = %d\n",a);
    enum Color color;
    color = RED;
    printf("%d\n",color);
    int arr[10] = {3,6,4,7,9,2,1,5,7,6};

    int area = maxArea(arr,10);

    printf("%d",area);
    return 0;
}
