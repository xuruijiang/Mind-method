//
//  main.c
//  test_10_12_Xcode_paly
//
//  Created by 徐瑞江 on 2022/10/12.
//
#include<stdio.h>
void paixu(double arr[], int n) {
    int i = 0;
    int j = 0;
    double z = 0;
    for (i = 0;i < n - 1;i++) {
        for (j = i + 1;j < n;j++) {
            if (arr[i] < arr[j]) {
                z = arr[i];
                arr[i] = arr[j];
                arr[j] = z;
            }
        }
    }

}
int main() {
    //void paixu(float arr[], int n);
    int n;
    int i = 0;
    int j = 0;

    double sum = 0;
    scanf("%d", &n);
    double arr1[10000];
    for (i = 0;i < n;i++) {
        scanf("%lf",&arr1[i]);
    }
    paixu(arr1, n);

    double arr2[10000];
    for (int j = 0;j < n;j++) {
        scanf("%lf",&arr2[j]);
    }
    paixu(arr2, n);
    for (i = 0, j = n - 1;i < n && j >= 0;i++ , j--) {
        sum += arr1[i] * arr2[j];
    }
    printf("%.3f", sum);
    return 0;
}
