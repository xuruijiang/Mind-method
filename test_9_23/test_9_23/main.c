//
//  main.c
//  test_9_23
//
//  Created by 徐瑞江 on 2022/9/23.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
int main(int argc, const char * argv[]) {

    
    char arr1[] = "welcome to bit!!!!!!";
    char arr2[] = "####################";
    int left = 0;
    int right =  (int)strlen(arr1) - 1;
    

    
    while (left <= right) {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n",arr2);
        sleep(1);
        //close(100);
        left++;
        right--;

    }
    return 0;
}
