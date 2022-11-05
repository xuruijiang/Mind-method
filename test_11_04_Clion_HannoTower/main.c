#include <stdio.h>
int cnt;
void hanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    hanoi(n - 1, a, c, b);//将n-1个盘子由A经过C移动到B
    printf("step %d: move %d from %c->%c\n", cnt++, n, a, c);
    hanoi(n - 1, b, a, c);//剩下的n-1盘子，由B经过A移动到C
}

int main()
{
    int n;
    scanf("%d", &n);

    cnt = 1;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}