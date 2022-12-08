#include <stdio.h>


struct node{
    int data;
    struct node * next;

}* pt;
int main() {

    struct node no = {1};
    pt = &no;
    struct node no1 = {2};

    no.next = &no1;
    pt->next->data = 2;

    printf("%d \n",no1.data);


    int a = 0;
    //a=a+2=3;
    double n = 0;
    double sum = 0;
    scanf("%lf",&n);

    for (int i = 1; i <= n; ++i) {

        sum += (1.0)/((i)*(i + 1));
    }

    printf("%.4lf",sum);
    return 0;
}
