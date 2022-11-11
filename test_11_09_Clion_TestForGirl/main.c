#include<stdio.h>
int hum(int j, int k, int n)
{
    if(n <= 2)
        return 1;
    if (n>2) {
        int i = 1;
        int c = 2;
        for (i = 2;i < n;i++)
        {
            int c = j + k;
            //c = j + k;
            j = k;
            k = c;
        }return c;
    }

}
int main()
{
    int j = 1;
    int k = 1;
    int n = 0;
    scanf("%d", &n);
    int h=hum(j, k, n);
    printf("%d\n", h);
    return 0;
}